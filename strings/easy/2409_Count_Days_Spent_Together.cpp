class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int monthDays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

        string date1 = min(leaveAlice, leaveBob);
        string date2 = max(arriveAlice, arriveBob);
        
        int d1 = monthDays[stoi(date1.substr(0, 2)) - 1] + stoi(date1.substr(2 + 1));
        int d2 = monthDays[stoi(date2.substr(0, 2)) - 1] + stoi(date2.substr(2 + 1));

        if (d1 < d2) return 0;
        return d1 - d2 + 1;
    }
};
