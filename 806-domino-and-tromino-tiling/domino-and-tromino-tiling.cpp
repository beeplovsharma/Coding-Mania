class Solution {
public:
    int dp[1001];
    const int MOD = 1e9+7;
    typedef long long ll;
    int fun(int n){
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;

        if(dp[n]!=-1) return dp[n];
        
        ll v = fun(n-1);
        ll h = fun(n-2);
        ll l = 0;
        for(int i=0;i<=n-3;i++){
            l=(l + 2*fun(i))%MOD;
        }

        int x = (v+h+l)%MOD;
        return dp[n] = x;
    }
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(n);
    }
};