class Solution {
public:
    int fun(string s, string t,int i,int j,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j] = 0+fun(s,t,i-1,j-1,dp);
        }
        else{
            int replace = 1+fun(s,t,i-1,j-1,dp);
            int del = 1+fun(s,t,i-1,j,dp);
            int ins = 1+fun(s,t,i,j-1,dp);
            return dp[i][j] = min(replace,min(del,ins));
        }
    }
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(s,t,n-1,m-1,dp);
    }
};