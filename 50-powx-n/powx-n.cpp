class Solution {
public:
    typedef long long ll;
    double fun(double x, ll n){
        if(n==0) return 1.0;

        double half = fun(x,n/2);
        double ans = half * half;

        if(n%2==1) ans = ans * x;

        return (double)ans;
    }
    double myPow(double x, int n) {
        double ans = fun(x,abs((ll)n));
        cout<<ans;
        if(n<0) return (double)(1/ans);

        return ans;
    }
};