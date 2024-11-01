class Solution {
public:
    int fun(vector<int>& nums,int ind, int amount,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(ind==0){
            if(amount%nums[0]==0) return (amount/nums[0]);
            return 1e9;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int notTake = fun(nums,ind-1,amount,dp);
        int take = 1e9;
        if(nums[ind]<=amount){
            take = 1 + fun(nums,ind,amount-nums[ind],dp);
        }


        return dp[ind][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(1e4+1,-1));
        int ans = fun(coins,n-1,amount,dp);
        if(ans==1e9) return -1;
        else return ans;
    }
};