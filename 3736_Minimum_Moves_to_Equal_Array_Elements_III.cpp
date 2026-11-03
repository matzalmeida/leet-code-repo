class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = INT_MIN, sum = 0;
        for (int& x : nums) {
            max_val = max(max_val, x);
        }
        for (int& x : nums) {
            sum += max_val - x;
        }
        return sum;
    }
};
