class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef long long ll;
    int tile(int n,vector<int>&dp) {
        if (n == 0) return 1;  
        if (n == 1) return 1;
        if (n == 2) return 2;

        if(dp[n]!=-1) return dp[n];

        ll v = tile(n - 1,dp);
        ll h = tile(n - 2,dp);
        ll l = 0;

        for (int i = 0; i <= n - 3; i++) {
            l = (l + 2LL * tile(i,dp)) % MOD;
        }

        int x = (v + h + l) % MOD;

        return dp[n] = x;
    }
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return tile(n,dp);
    }
};