class Solution {
public:
    int dp[13][10001];
    int fun(vector<int>& coins,int ind, int tamt){
        if(ind==coins.size()){
            if(tamt==0) return 0;
            return 1e9;
        }
        if(dp[ind][tamt]!=-1) return dp[ind][tamt];
        //skip
        int skip = fun(coins,ind+1,tamt);
        //choose
        int choose = 1e9;
        if(tamt-coins[ind]>=0) 
            choose = 1 + fun(coins,ind,tamt-coins[ind]);

        return dp[ind][tamt] = min(skip,choose);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans =fun(coins,0,amount);
        return ans >= 1e9 ? -1 : ans;
    }
};