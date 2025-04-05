class Solution {
public:
    int fun(vector<int>& coins, int ind ,int amount,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(ind==coins.size() || amount<0){
            return 1e9;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int pick = 1 + fun(coins,ind,amount-coins[ind],dp);
        int notPick = fun(coins,ind+1,amount,dp);

        return dp[ind][amount] = min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = fun(coins,0,amount,dp);
        return ans==1e9 ? -1 : ans;
    }
};