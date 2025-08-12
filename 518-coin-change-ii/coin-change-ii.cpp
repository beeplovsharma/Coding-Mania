class Solution {
public:
    int dp[301][5001];
    int fun(vector<int>& coins,int ind,int amt){
        if(ind==coins.size()){
            return amt==0;
        }

        if(dp[ind][amt]!=-1) return dp[ind][amt];

        int skip = fun(coins,ind+1,amt);
        int choose = 0;
        if(amt-coins[ind]>=0) choose = fun(coins,ind,amt-coins[ind]);

        return dp[ind][amt] = (skip + choose);
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return fun(coins,0,amount);
    }
};