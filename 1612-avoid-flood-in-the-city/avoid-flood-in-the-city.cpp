
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
    std::vector<int> avoidFlood(std::vector<int>& rains) {
        int n = rains.size();
        std::vector<int> ans(n);
        std::unordered_map<int, int> fullLakes;  // lake -> last day it was full
        std::set<int> dryDays;  // indices of days where we can dry a lake

        for (int i = 0; i < n; ++i) {
            int lakeId = rains[i];

            if (lakeId == 0) {
                // Dry day: we can choose which lake to dry later
                dryDays.insert(i);
                ans[i] = 1; // Default dry any lake; may be updated later
            } else {
                // Rainy day
                if (fullLakes.count(lakeId)) {
                    int lastFullDay = fullLakes[lakeId];

                    // Find the earliest dry day after last full day
                    auto it = dryDays.lower_bound(lastFullDay + 1);
                    if (it == dryDays.end()) {
                        // No dry day to prevent flood
                        return {};
                    }

                    int dryDay = *it;
                    ans[dryDay] = lakeId; // Dry this lake on dryDay
                    dryDays.erase(it);
                }

                // Update the lake as full on current day
                fullLakes[lakeId] = i;
                ans[i] = -1; // It rained on this day
            }
        }

        return ans;
    }
};

        
    