class Solution {
public:
    bool isSortable(vector<int>& nums, int left, int right, int& left_max) {
        bool isSortable = true;
        int inflexPoints = 0, max_val = INT_MIN, min_val = INT_MAX;
        for (int i = left; i <= right; i++) {
            max_val = max(max_val, nums[i]);
            min_val = min(min_val, nums[i]);
        }
        int j = right;
        for (int i = left; i <= right && inflexPoints < 2; i++) {
            if (!(nums[i] >= nums[j])) {
                inflexPoints++;
            }
            j = i;
        }
        if (inflexPoints < 2 && min_val >= left_max) {
            left_max = max_val;
            return true;
        }
        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> k;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                k.push_back(i);
            }
        }
        int ans = 0;
        for (int x : k) {
            int left = 0, right = left + x - 1, left_max = INT_MIN;
            bool k_isSortable = true;
            while (right < n) {
                if (!isSortable(nums, left, right, left_max)) {
                    k_isSortable = false;
                    break;
                }
                left = left + x;
                right = left + x - 1;
            }
            if (k_isSortable) ans += x;
        }
        return ans;
    }
};
