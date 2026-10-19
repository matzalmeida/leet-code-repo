class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.size() - 1, left = -1, right = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                left = mid;
                hi = mid - 1;
            }
        }
        lo = 0; hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                right = mid;
                lo = mid + 1;
            }
        }
        vector<int> ans;
        for (int i = left; i <= right && i >= 0; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};
