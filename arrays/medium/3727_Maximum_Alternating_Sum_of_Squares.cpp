class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;

        sort(nums.begin(), nums.end(),
        [](int a, int b) { return abs(a) < abs(b); });

        int lo = 0, hi = nums.size() - 1, i = 0;
        while (lo <= hi) {
            if (i % 2 == 0) {
                ans += nums[hi] * nums[hi];
                hi--;
            } else {
                ans -= nums[lo] * nums[lo];
                lo++;
            }
            i++;
        }

        return ans;
    }
};
