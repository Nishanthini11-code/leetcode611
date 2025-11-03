class Solution {
    public int minCost(String colors, int[] neededTime) {
        int totalCost = 0;
        int prevMaxTime = 0; // Stores the maximum time of the previously considered balloon in a consecutive group

        for (int i = 0; i < colors.length(); i++) {
            // If the current balloon's color is different from the previous one,
            // or if it's the first balloon, reset prevMaxTime as a new group starts.
            if (i > 0 && colors.charAt(i) != colors.charAt(i - 1)) {
                prevMaxTime = 0;
            }

            int currentTime = neededTime[i]; // Time to remove the current balloon

            // If prevMaxTime is not zero (meaning there's a previous balloon of the same color),
            // we need to remove one of them. Add the minimum of the two times to the total cost.
            // Then, update prevMaxTime to be the maximum of the two, as we are keeping the one
            // with the higher removal time.
            if (prevMaxTime != 0) {
                totalCost += Math.min(prevMaxTime, currentTime);
                prevMaxTime = Math.max(prevMaxTime, currentTime);
            } else {
                // If there's no previous balloon of the same color, this is the first
                // balloon in a new consecutive group, so we just set prevMaxTime to its time.
                prevMaxTime = currentTime;
            }
        }
        return totalCost;
    }
}
        
        
    
