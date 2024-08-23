class Solution {
public:
    int fun(vector<int>& nums,int ind,vector<int>&dp){
        if(ind>=nums.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int steal = nums[ind] + fun(nums,ind+2,dp);
        int notSteal = 0 + fun(nums,ind+1,dp);

        return dp[ind] = max(steal,notSteal);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return fun(nums,0,dp);
    }
};