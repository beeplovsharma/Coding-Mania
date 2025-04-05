class Solution {
public:
    int fun(vector<int>& nums, int ind, int amount,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(ind==nums.size() || amount<0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int pick = fun(nums,ind,amount-nums[ind],dp);
        int notPick = fun(nums,ind+1,amount,dp);

        return dp[ind][amount] = (pick+notPick);
    }
    int change(int amount, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fun(nums,0,amount,dp);
    }
};