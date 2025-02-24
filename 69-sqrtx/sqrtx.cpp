class Solution {
public:
    int mySqrt(int n) {
        if(n==0 || n==1) return n;

        int lo = 0, hi = n;
        while(hi-lo>1){
            int mid = hi+(lo-hi)/2;

            if(mid<=n/mid) lo = mid;
            else hi = mid-1;
        }

        if(hi<=n/hi) return hi;
        if(lo<=n/lo) return lo;

        return -1;
    }
};