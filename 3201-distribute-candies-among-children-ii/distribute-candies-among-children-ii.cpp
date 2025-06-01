class Solution {
public:
    typedef long long ll;
    ll starsAndBars(int n){
        ll ans = (n+1) * 1LL * (n+2) /2;
        return ans;
    }
    long long distributeCandies(int n, int limit) {
        ll allCase = starsAndBars(n);
        ll a = 0;
        if((n-(limit+1)>=0)) a = 3*starsAndBars((n-(limit+1))); 
        ll ab = 0;
        if((n-2*(limit+1))>=0) ab = 3*starsAndBars((n-2*(limit+1)));
        ll abc = 0;
        if((n-3*(limit+1))>=0) abc = starsAndBars((n-3*(limit+1)));

        return allCase-(a-ab+abc);
    }
};