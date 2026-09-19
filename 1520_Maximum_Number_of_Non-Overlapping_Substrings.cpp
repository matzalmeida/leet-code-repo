class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        // buckets
        vector<pair<int,int>> substrings(26, {-1,-1});
        // initialize
        for (int i = 0; i < s.length(); i++) {
            if (substrings[s[i]-'a'].first == -1) {
                substrings[s[i]-'a'] = {i, i};
            } else {
                substrings[s[i]-'a'].second = i;
            }
        }
        // merge, could be optimized
        for (int i = 0; i < substrings.size(); i++) {
            auto &left = substrings[i].first;
            auto &right = substrings[i].second;
            if (left > -1) {
                bool stable = false;
                string nova;
                while (!stable) {
                    string substring = s.substr(left, right-left+1);
                    for (char c : substring) {
                        int j = c - 'a';
                        auto& leftj = substrings[j].first;
                        auto& rightj = substrings[j].second;
                        if (j != i && leftj > -1 ) {
                            left = min(left, leftj);
                            right = max(right, rightj);
                        }
                    }
                    nova = s.substr(left, right-left+1);
                    if (nova.compare(substring) == 0) {
                        stable = true;
                    }
                }
            }
        }
        // sort
        sort(substrings.begin(), substrings.end(), [](auto &left, auto &right) {
            return left.second < right.second;
        });
        // greedy
        vector<string> solution;
        int last_end = -1;
        for (int i = 0; i < substrings.size(); i++) {
            auto &left = substrings[i].first;
            auto &right = substrings[i].second;
            
            if (left > last_end) {
                last_end = right;
                solution.push_back(s.substr(left, right-left+1));
            }
        }
        return solution;
    }
};
