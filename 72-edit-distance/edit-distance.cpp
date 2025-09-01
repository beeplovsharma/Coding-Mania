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
        vector<int>cur(m+1,0), prev(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = j;

        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                int mini = INT_MAX;
                if(s1[i-1]==s2[j-1]){
                    mini = min(mini,prev[j-1]);
                }else{
                    int ins = 1 + cur[j-1];
                    int del = 1 + prev[j];
                    int repl = 1 + prev[j-1];

                    mini = min({mini,ins,del,repl});
                }

                cur[j] = mini;
            }
            prev = cur;
        }
        return prev[m];
    }
};