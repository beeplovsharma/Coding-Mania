class Solution {
public:
    int fun(int n, vector<int>&dp){
        if(n<=0) return -1e9;
        if(n==1 || n==2) return 1; 

        if(dp[n]!=-1) return dp[n];

        int maxi = -1e9;
        for(int p=1;p<n;p++){
            int notSplit = p * (n-p); 
            int split = p * fun(n-p,dp);

            maxi = max({maxi,split,notSplit});
        }

        return dp[n] = maxi;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};