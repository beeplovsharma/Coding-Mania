class Solution {
public:
    typedef long long ll;
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
        vector<ll>cur(m+1,0),prev(m+1,0);
        //base case
        cur[0]=1;
        prev[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans = 0;
                if(s[i-1]==t[j-1]){
                    ans = prev[j-1] + prev[j];
                }else{
                    ans = prev[j];
                }
                cur[j] = ans;
            }
            prev = cur;
        }

        return cur[m];
    }
};