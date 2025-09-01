class Solution {
public:
    int fun(string &s, string &t,int i,int j,vector<vector<int>>&dp){
        if(j==0) return 1;
        if(i==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;
        if(s[i-1]==t[j-1]){
            ans = fun(s,t,i-1,j-1,dp) + fun(s,t,i-1,j,dp);
        }else{
            ans = fun(s,t,i-1,j,dp);
        }

        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(s,t,n,m,dp);
    }
};