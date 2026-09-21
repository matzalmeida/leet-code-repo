class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k, 0));
        vector<long long> ans(k, 0);
        dp[0][nums[0] % k]++;
        ans[nums[0] % k]++;
        for (int i = 1; i < n; i++) {
            dp[i][nums[i] % k]++;
            for (int r = 0; r < k; r++) {
                long long val = dp[i-1][r];
                if (val > 0) {
                    int new_r = r * (nums[i] % k) % k;
                    dp[i][new_r] += val;
                }
            }
            for (int r = 0; r < k; r++) {
                ans[r] += dp[i][r];
            }
        }
        return ans;
    }
};
