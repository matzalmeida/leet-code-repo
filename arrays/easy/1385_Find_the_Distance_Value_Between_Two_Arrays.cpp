class Solution {
public:
    int findClosest(vector<int>& arr, int goal) {
        int lo = 0, hi = arr.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] == goal)
                return arr[mid];

            if (arr[mid] < goal)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        // hi aponta para o elemento à esquerda
        // lo aponta para o elemento à direita

        if (hi < 0)
            return arr[lo];

        if (lo >= arr.size())
            return arr[hi];

        int left = arr[hi];
        int right = arr[lo];

        if (goal - left <= right - goal)
            return left;

        return right;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = arr1.size();

        sort(arr2.begin(), arr2.end());
        for (int i = 0; i < arr1.size(); i++) {
            int prox = abs(arr1[i] - findClosest(arr2, arr1[i]));
            if (prox <= d) ans--;
        }
        return ans;
    }
};
