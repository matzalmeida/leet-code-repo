class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> word;
        for (vector<string> &keyvalue : knowledge) {
            word[keyvalue[0]] = keyvalue[1];
        }
        string ans, key;
        stack<char> brackets;
        for (char c : s) {
            if (c == '(') {
                brackets.push(c);
                key = "";
            } else if (c == ')') {
                brackets.pop();
                if (word.find(key) != word.end()) {
                    ans += word[key];
                } else {
                    ans += '?';
                }
            } else if (brackets.empty()) {
                ans += c;
            } else {
                key += c;
            }
        }
        return ans;
    }
};
