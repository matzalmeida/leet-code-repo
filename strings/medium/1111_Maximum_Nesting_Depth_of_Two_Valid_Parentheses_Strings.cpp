class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.length(), -1);
        vector<int> aux({0,0});
        int i = 0;
        for (char& c : seq) {
            if (c == '(') {
                int smaller_idx = aux[0] < aux[1] ? 0 : 1;
                aux[smaller_idx]++;
                ans[i] = smaller_idx;
            } else if (c == ')') {
                int bigger_idx = aux[0] > aux[1] ? 0 : 1;
                aux[bigger_idx]--;
                ans[i] = bigger_idx;
            }
            i++;
        }
        return ans;
    }
};
