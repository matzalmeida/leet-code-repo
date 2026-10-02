class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<pair<vector<int>,string>> st;
        vector<string> ans;
        st.push({{0,0},""});
        while(!st.empty()) {
            pair<vector<int>,string> curr = st.top();
            st.pop();
            if (curr.first[1] > curr.first[0]) {
                continue;
            }
            if (curr.first[1] == n && curr.first[0] == n) {
                ans.push_back(curr.second);
            }
            if (curr.first[0] > curr.first[1]) {
                st.push({{curr.first[0], curr.first[1] + 1}, curr.second + ')'});
            }
            if (curr.first[0] < n) {
                st.push({{curr.first[0] + 1, curr.first[1]}, curr.second + '('});
            }
        }
        return ans;
    }
};
