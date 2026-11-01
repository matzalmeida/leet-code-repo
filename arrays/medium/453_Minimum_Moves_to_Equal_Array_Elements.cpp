class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minV = INT_MAX;
        for (int i = 0; i < n; i++) {
            minV = min(nums[i], minV);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += nums[i] - minV;
        } 
        return ans;
    }
};
