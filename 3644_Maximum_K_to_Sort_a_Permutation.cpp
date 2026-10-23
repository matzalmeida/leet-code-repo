class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int N = nums.size(), ans = INT_MAX;
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
                ok = false;
            } 
        }
        return ok ? 0 : ans;
    }
};
