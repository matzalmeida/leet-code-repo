class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last_seen = INT_MIN, cnt = 0;
        for (int i : nums) {
            if (last_seen != i) {
                nums[cnt] = i;
                cnt++;
            }
            last_seen = i;
        }
        return cnt;
    }
};
