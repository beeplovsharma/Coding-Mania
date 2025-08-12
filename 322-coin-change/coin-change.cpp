class Solution {
public:
    int dp[13][10001];
    int fun(vector<int>& coins,int ind, int tamt){
        if(ind==coins.size()){
            if(tamt==0) return 0;
            return INT_MAX/2;
        }
        if(dp[ind][tamt]!=-1) return dp[ind][tamt];
        //skip
        int skip = fun(coins,ind+1,tamt);
        //choose
        int choose = INT_MAX/2;
        if(tamt-coins[ind]>=0) 
            choose = 1 + fun(coins,ind,tamt-coins[ind]);

        return dp[ind][tamt] = min(skip,choose);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans =fun(coins,0,amount);
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};