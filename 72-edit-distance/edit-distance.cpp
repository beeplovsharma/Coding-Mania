class Solution {
public:
    int dp[501][501];
    int fun(string &s1, string &s2, int i, int j){
        if(j<0) return i+1;
        if(i<0) return j+1;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = INT_MAX;
        if(s1[i]==s2[j]){
            mini = min(mini,fun(s1,s2,i-1,j-1));
        }else{
            int ins = 1 + fun(s1,s2,i,j-1);
            int del = 1 + fun(s1,s2,i-1,j);
            int repl = 1 + fun(s1,s2,i-1,j-1);

            mini = min({mini,ins,del,repl});
        }

        return dp[i][j] = mini;
    }
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        memset(dp,-1,sizeof(dp));
        return fun(s1,s2,n-1,m-1);
    }
};