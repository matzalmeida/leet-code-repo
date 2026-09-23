class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long total = 0;

        // get total sum of the vector
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        // find the value needed to the maximum subarray
        long long target = total - x;

        // if target value is less than 0, it's impossible
        if (target < 0) {
            return -1;
        }

        // if target value is equal to 0, all n elements are needed
        if (target == 0) {
            return n;
        }

        int left = 0;
        long long sum = 0;
        int maxLen = -1;

        // sliding-window to find maximum subarrays
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // remove left elements of the maximum subarray until sum is less than target
            while (left <= right && sum > target) {
                sum -= nums[left++];
            }
            
            // if sum equals target, then it's a valid maximum subarray
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // return the number elements minus the length of the valid maximum subarray
        return maxLen == -1 ? -1 : n - maxLen;
    }
};
