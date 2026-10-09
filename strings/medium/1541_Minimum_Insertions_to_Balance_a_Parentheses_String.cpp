class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0, n = s.length();
        stack<bool> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(true);
            } else {
                if (i < n - 1) {
                    if (s[i+1] == ')') {
                        if (st.empty()) {
                            cnt++;
                        } else {
                            st.pop();
                        }
                        i++;
                    } else {
                        if (st.empty()) {
                            cnt+=2;
                        } else {
                            cnt++;
                            st.pop();
                        }
                    }
                } else {
                    if (!st.empty()) {
                        cnt++;
                        st.pop();
                    } else {
                        cnt += 2;
                    }
                }
            }
        }
        return cnt + st.size() * 2;
    }
};
