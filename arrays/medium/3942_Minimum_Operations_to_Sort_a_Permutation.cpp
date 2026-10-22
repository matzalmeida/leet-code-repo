class Solution {
public:
    int minOperations(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return 0;
        if (N == 2) return nums[1] >= nums[0] ? 0 : 1;
        
        int prev = nums[N-1], inflexPoints = 0, inflexIdx = -1;
        for (int i = 0; i < N && inflexPoints <= 1; i++) {
            int x = nums[i];
            if (x < prev) {
                inflexPoints++;
                inflexIdx = i;
            }
            prev = x;
        }
        if (inflexPoints == 1) {
            return min(inflexIdx, 2 + (N - inflexIdx) % N);
        }

        int prev_idx = N - 1;
        inflexPoints = 0;
        for (int i = 0; i < N && inflexPoints <= 1; i++) {
            int x = nums[i];
            if (x > nums[prev_idx]) {
                inflexPoints++;
                inflexIdx = i;
            }
            prev_idx = i;
        }
        if (inflexPoints == 1) {
            // reverse after
            cout << inflexIdx;
            int reverse_after = 1 + inflexIdx;
            // reverse first
            prev = N - 1; inflexPoints = 0; inflexIdx = -1;
            reverse(nums.begin(), nums.end());
            for (int i = 0; i < N && inflexPoints <= 1; i++) {
                int x = nums[i];
                if (x < prev) {
                    inflexPoints++;
                    inflexIdx = i;
                }
                prev = x;
            }
            int reverse_first = 1 + min(inflexIdx, 2 + (N - inflexIdx) % N);
            
            return min(reverse_first, reverse_after);
        }

        return -1;
    }
};
