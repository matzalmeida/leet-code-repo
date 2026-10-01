class Solution {
public:
    bool isValid(string s) {
        stack<char> p_stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                p_stack.push(c);
            else if ( !p_stack.empty() && c == p_stack.top() + ( c > 50 ? 2 : 1) )
                p_stack.pop();
            else
                return false;
        }
        return p_stack.empty();
    }
};
