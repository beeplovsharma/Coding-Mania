class Solution {
public:
    int fun(string &a,string &b,int i,int j,vector<vector<int>>&dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0,notTake=0;
        if(a[i-1]==b[j-1])
            take = 1+fun(a,b,i-1,j-1,dp);
        else notTake = max(fun(a,b,i-1,j,dp),fun(a,b,i,j-1,dp));
        
        return dp[i][j] = max(take,notTake);
    }
    int longestCommonSubsequence(string a, string b) {
        int n = a.size(),m = b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int take = 0,notTake=0;
                if(a[i-1]==b[j-1])
                    take = 1+dp[i-1][j-1];
                else notTake = max(dp[i-1][j],dp[i][j-1]);
                
                dp[i][j] = max(take,notTake);
            }
        }
        return dp[n][m];
    }
};