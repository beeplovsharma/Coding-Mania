class Solution {
public:

    typedef long long ll;

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ll cnt = 0;

        for(int i = 0; i < n; ++i) {
            int low = lower - nums[i];
            int high = upper - nums[i];

            auto left = lower_bound(nums.begin() + i + 1, nums.end(), low);
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), high);

            cnt += (right - left);
        }

        return cnt;
    }
};