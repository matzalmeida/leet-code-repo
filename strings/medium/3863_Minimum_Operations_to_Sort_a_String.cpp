class Solution {
public:
    int minOperations(string s) {
        if (s.length() == 1) return 0;
        bool isSorted = true;
        int mn_idx = -1, mx_idx = -1, i = 0;
        char prev = 0, mn = CHAR_MAX, mx = CHAR_MIN;
        for (char& c : s) {
            if (c < prev) {
                isSorted = false;
            }
            prev = c;
            if (mn > c) {
                mn = c;
                mn_idx = i;
            }
            if (mx <= c) {
                mx = c;
                mx_idx = i;
            }
            i++;
        }
        if (isSorted) return 0;
        else if (s.length() == 2) return -1;
        if (mx == s[s.length()-1] || mn == s[0]) return 1;
        else if (mx_idx < 1 && mn_idx == s.length() - 1) return 3;
        return 2;
    }
};
