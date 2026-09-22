// TLE, not solved... Need to use segment tree and it's using DP. Time Limit Exceeded 775 / 783 testcases passed
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        int cnt = 0;
        
        for (vector<int>& query : queries) {
            nums[query[0]] = query[1];
            
            int dp = nums[query[2]] % k;
            if (dp == query[3]) ans[cnt]++;
            for (int i = query[2] + 1; i < nums.size(); i++) {
                int new_r = dp * (nums[i] % k) % k;
                dp = new_r;
                if (dp == query[3]) ans[cnt]++;
            }
        
            cnt++;
        }
        return ans;
    }
};
