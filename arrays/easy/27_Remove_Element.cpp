class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                k++;
            } else {
                nums[i-k] = nums[i];
            }
        }
        return n-k;
    }
};
