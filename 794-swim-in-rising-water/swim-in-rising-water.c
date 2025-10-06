#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int r;
    int c;
} Cell;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool canReach(int** grid, int gridSize, int* gridColSize, int t) {
    if (grid[0][0] > t) return false;

    bool** visited = (bool**)malloc(gridSize * sizeof(bool*));
    for (int i = 0; i < gridSize; ++i) {
        visited[i] = (bool*)calloc(gridColSize[0], sizeof(bool));
    }
    Cell* queue = (Cell*)malloc(gridSize * gridColSize[0] * sizeof(Cell));
    int front = 0, rear = 0;

    queue[rear++] = (Cell){0, 0};
    visited[0][0] = true;

    while (front < rear) {
        Cell current = queue[front++];
        if (current.r == gridSize - 1 && current.c == gridColSize[0] - 1) {
            for (int i = 0; i < gridSize; ++i) free(visited[i]);
            free(visited);
            free(queue);
            return true;
        }

        for (int d = 0; d < 4; ++d) {
            int nr = current.r + dr[d];
            int nc = current.c + dc[d];

            if (nr >= 0 && nr < gridSize && nc >= 0 && nc < gridColSize[0] &&
                !visited[nr][nc] && grid[nr][nc] <= t) {
                visited[nr][nc] = true;
                queue[rear++] = (Cell){nr, nc};
            }
        }
    }
    for (int i = 0; i < gridSize; ++i) free(visited[i]);
    free(visited);
    free(queue);

    return false;
}

int swimInWater(int** grid, int gridSize, int* gridColSize) {
    int low = 0;
    int high = gridSize * gridSize - 1;
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canReach(grid, gridSize, gridColSize, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
