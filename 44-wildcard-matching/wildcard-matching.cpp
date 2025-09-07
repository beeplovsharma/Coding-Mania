class Solution {
public:
    bool fun(string &s, string &p,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return true;
        if(i==0 && j>=1){
            for(int k=j;k>=1;k--){
                if(p[k-1]!='*') return false;
            }
            return true;
        }
        if(i>=1 && j==0){
            return false;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            if(fun(s,p,i-1,j-1,dp)) return dp[i][j] = true;
        }else if(p[j-1]=='*'){
            if(fun(s,p,i,j-1,dp) || fun(s,p,i-1,j,dp) || fun(s,p,i-1,j-1,dp)) return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return fun(s,p,n,m,dp);
    }
};