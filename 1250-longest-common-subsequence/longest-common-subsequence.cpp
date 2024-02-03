class Solution {
public:
    int fun(int i,int j,string s, string t,vector<vector<int>>&dp){

        if(i==0 || j==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==t[j-1]) return dp[i][j] = 1 + fun(i-1,j-1,s,t,dp);

        return dp[i][j] = max(fun(i-1,j,s,t,dp),fun(i,j-1,s,t,dp));
    }

    int longestCommonSubsequence(string s, string t) {
        int n1 = s.size(),n2 = t.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        // return fun(n1,n2,text1,text2,dp);
        vector<int>prev(n2+1,0),cur(n2+1,0);
        for(int i=0;i<=n1;i++) prev[0] = 0;
        for(int j=0;j<=n2;j++) dp[0][j] = 0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]) cur[j] = 1 + prev[j-1];

                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        return cur[n2];
    }
};