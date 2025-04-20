class Solution {
public:
    int fun(vector<int>& nums, int ind, int prevIdx,vector<vector<int>>&dp) {
        if (ind == nums.size()) {
            return 0;
        }

        if (dp[ind][prevIdx+1]!=-1) return dp[ind][prevIdx+1];

        int notPick = fun(nums, ind + 1, prevIdx, dp);
        int pick = 0;
        if (prevIdx == -1 || nums[ind] > nums[prevIdx]) {
            pick = 1 + fun(nums, ind + 1, ind, dp);
        }

        return dp[ind][prevIdx+1] = max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prevIdx=ind-1;prevIdx>=-1;prevIdx--){
                int notPick = dp[ind + 1][prevIdx+1];
                int pick = 0;
                if (prevIdx == -1 || nums[ind] > nums[prevIdx]) {
                    pick = 1 + dp[ind + 1][ind+1];
                }
                dp[ind][prevIdx+1] = max(pick, notPick);
            }
        }
        return dp[0][-1+1];
    }

};
