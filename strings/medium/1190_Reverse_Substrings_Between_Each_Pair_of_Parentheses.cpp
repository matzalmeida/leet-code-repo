class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> words;
        words.push("");
        for (char c : s) {
            if (c == '(') {
                words.push("");
            } else if (c == ')') {
                string new_word = words.top();
                int length = new_word.length();
                for (int i = 0; i < length / 2; i++) {
                    char aux = new_word[i];
                    new_word[i] = new_word[length-i-1];
                    new_word[length-i-1] = aux;
                }
                words.pop();
                words.top() += new_word;
            } else {
                words.top() += c;
            }
        }
        return words.top();
    }
};
