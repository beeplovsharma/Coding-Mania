// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while(hi-lo>1){
            int mid = hi+(lo-hi)/2;
            if(isBadVersion(mid)==false) lo = mid+1;
            else hi = mid;
        }

        if(isBadVersion(lo)) return lo;
        if(isBadVersion(hi)) return hi;

        return -1;
    }
};