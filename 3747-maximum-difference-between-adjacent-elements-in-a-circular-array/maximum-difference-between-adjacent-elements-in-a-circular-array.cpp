class Solution {
public:
    int circularIndex(int i, int n) {
        return (i % n + n) % n; // handles negative indices correctly
    }

    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;

        for (int i = 1; i < 2 * n; i++) {
            int idx = circularIndex(i, n);
            int prevIdx = circularIndex(i - 1, n);

            maxi = max(maxi, abs(nums[idx] - nums[prevIdx]));
        }

        return maxi;
    }
};
