class Solution {
    public int totalMoney(int n) {
         int total = 0;
        int currentMondayDeposit = 1; // Amount deposited on the current week's Monday

        for (int day = 1; day <= n; day++) {
            int dayOfWeek = (day - 1) % 7; // 0 for Monday, 1 for Tuesday, ..., 6 for Sunday

            if (dayOfWeek == 0) { // It's a Monday
                total += currentMondayDeposit;
            } else { // It's not a Monday
                total += (currentMondayDeposit + dayOfWeek);
            }

            if (dayOfWeek == 6) { // End of the week, prepare for next Monday
                currentMondayDeposit++;
            }
        }
        return total;
    }
}
        
        
    
