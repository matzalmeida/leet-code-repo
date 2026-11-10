class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        int i = 1;
        while (i <= n) {
            int minCost = INT_MAX;
            for (int j = 1; j <= 3 && i-j >= 0; j++) {
                minCost = min(minCost, dp[i-j] + costs[i-1] + j*j);
            }
            dp[i] = minCost;
            i++;
        }
        return dp[n];
    }
};
