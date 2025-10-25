int totalMoney(int n) {
    int total = 0;
    int current_week_start_deposit = 1; // Deposit for the first Monday of the current week

    for (int day = 1; day <= n; day++) {
        int day_of_week = (day - 1) % 7; // 0 for Monday, 1 for Tuesday, ..., 6 for Sunday
        
        // Calculate deposit for the current day
        // It's the starting deposit of the week plus the day's offset within the week
        total += (current_week_start_deposit + day_of_week);

        // If it's the end of a week (Sunday), increment the starting deposit for the next week
        if (day_of_week == 6) { // If it's Sunday
            current_week_start_deposit++;
        }
    }
    return total;
}
    
