class Solution {
public:
    typedef long long ll;
    long long fun(vector<vector<int>>& questions,int ind,vector<ll>&dp){
        if(ind>=questions.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        ll solve = questions[ind][0] + fun(questions,ind+questions[ind][1]+1,dp);
        ll skip = fun(questions,ind+1,dp);

        return dp[ind] = max(solve,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll>dp(n,-1);
        return fun(questions,0,dp);
    }
};