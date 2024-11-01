class Solution {
public:
    int fun(string s,string t,int i,int j,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int one = 0;
        int two = 0;
        if(s[i]==t[j])
            one = fun(s,t,i-1,j-1,dp) + fun(s,t,i-1,j,dp);
        else
            two = fun(s,t,i-1,j,dp);
        
        return dp[i][j] = one+two;
    }
    int numDistinct(string s, string t) {
        int n = s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(s,t,n-1,m-1,dp);
    }
};