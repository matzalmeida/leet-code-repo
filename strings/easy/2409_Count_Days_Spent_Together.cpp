class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDays = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

        vector<string> dates = {arriveAlice, arriveBob, leaveAlice, leaveBob};
        vector<int> days;
        for (string& date : dates) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(2 + 1));
            days.push_back(monthDays[month-1] + day);
        }
        int ans = min(days[2], days[3]) - max(days[0], days[1]);
        
        return ans > 0 ? ans + 1 : ans == 0 ? 1 : 0;
    }
};
