class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt = 0;
        for (char& c : s) {
            if (c == '(') {
                if (cnt) {
                    ans += c;
                }
                cnt++;
            } else {
                cnt--;
                if (cnt) {
                    ans += c;
                }
            }
        }
        return ans;
    }
};
