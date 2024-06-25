class Solution {
public:
    int fun(vector<int>& num, int tar, int ind,vector<vector<int>>&dp) {

        if (tar == 0)
            return 0;
        if (ind == 0) {
            if (tar % num[0] == 0)
                return tar / num[0];
            return 1e9;
        }

        if(dp[tar][ind]!=-1) return dp[tar][ind];

        int notPick = fun(num, tar, ind - 1,dp);
        int pick = 1e9;
        if (tar >= num[ind])
            pick = 1 + fun(num, tar - num[ind], ind,dp);

        return dp[tar][ind] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(1e4,vector<int>(n,-1));
        if(fun(coins,amount,n-1,dp)==1e9) return -1;
        else return fun(coins,amount,n-1,dp);
    }
};