class Solution {
public:
    int dp[2001][2001];
    bool fun(string &s, string &p,int i,int j){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0){
            for(int k=j;k>=0;k--){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==p[j] || p[j]=='?'){
            if(fun(s,p,i-1,j-1)) return dp[i][j] = true;
        }else if(p[j]=='*'){
            if(fun(s,p,i,j-1) || fun(s,p,i-1,j) || fun(s,p,i-1,j-1)) return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int m = p.size();
        return fun(s,p,n-1,m-1);
    }
};