class Solution {
public:
    int fun(string &s1, string &s2, int i, int j,vector<vector<int>>&dp){
        if(j==0) return i;
        if(i==0) return j;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = INT_MAX;
        if(s1[i-1]==s2[j-1]){
            mini = min(mini,fun(s1,s2,i-1,j-1,dp));
        }else{
            int ins = 1 + fun(s1,s2,i,j-1,dp);
            int del = 1 + fun(s1,s2,i-1,j,dp);
            int repl = 1 + fun(s1,s2,i-1,j-1,dp);

            mini = min({mini,ins,del,repl});
        }

        return dp[i][j] = mini;
    }
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(s1,s2,n,m,dp);
    }
};