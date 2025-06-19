class Solution {
public:
    typedef long long ll;
    bool feasible(int n, int ind, int req, int maxSum) {
        long sum = req;  // value at index
        int left = ind;
        int right = n - ind - 1;

        // Left side
        if (req > left) {
            sum += (long)(req - 1 + req - left) * left / 2;
        } else {
            sum += (long)(req - 1) * req / 2;
            sum += left - (req - 1);
        }

        // Right side
        if (req > right) {
            sum += (long)(req - 1 + req - right) * right / 2;
        } else {
            sum += (long)(req - 1) * req / 2;
            sum += right - (req - 1);
        }

        return sum <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        int lo = 0;
        int hi = maxSum;

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(feasible(n,index,mid,maxSum)) lo=mid;
            else hi=mid;
        }

        if(feasible(n,index,hi,maxSum)) return hi;
        if(feasible(n,index,lo,maxSum)) return lo;

        return -1;
    }
};