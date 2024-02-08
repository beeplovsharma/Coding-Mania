class Solution {
public:
    int fun(int ind,vector<int>&dp){
        if(ind==0) return 1;
        if(ind==1) return 2;
        if(dp[ind]!=-1) return dp[ind];
        int f = 0,s=0;
        if(ind>=1) f = fun(ind-1,dp);
        if(ind>=2) s = fun(ind-2,dp);
        
        return dp[ind] = f+s;
    }
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return fun(n-1,dp);
    }
};