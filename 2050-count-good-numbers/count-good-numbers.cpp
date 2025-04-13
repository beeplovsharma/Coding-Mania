class Solution {
public:
    const int mod = 1e9+7;
    typedef long long ll;
    ll power(ll x, ll n){
        if(n == 0) return 1;
        ll ans = power(x, n / 2);
        ans = (ans * ans) % mod;
        if(n % 2 == 1) ans = (ans * x) % mod;
        return ans;
    }


    int countGoodNumbers(long long n) {
        ll a = power(5,n/2);
        ll b = power(4,n/2);
        ll c = 5;

        return (a*b*(n&1?c:1))%mod;
    }
};