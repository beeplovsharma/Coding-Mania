class Solution {
public:
    int fun(vector<int>& nums, int n, vector<int>& dp){
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0], nums[1]);

        if(dp[n] != -1) return dp[n];

        int steal = nums[n] + fun(nums, n-2, dp);
        int skip = fun(nums, n-1, dp);

        return dp[n] = max(steal, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> nums1 = nums;
        nums1.erase(nums1.begin());

        vector<int> nums2 = nums;
        nums2.pop_back();

        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);

        int ans1 = fun(nums1, n-2, dp1);
        int ans2 = fun(nums2, n-2, dp2);

        return max(ans1, ans2);
    }
};