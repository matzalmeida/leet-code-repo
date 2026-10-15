class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        set<int> buckets;
        for (int i = 0; i < nums.size(); i++) {
            buckets.clear();
            for (int j = i; j < nums.size(); j++) {
                buckets.insert(nums[j]);
                ans += buckets.size() * buckets.size();
            }
        }
        return ans;
    }
};
