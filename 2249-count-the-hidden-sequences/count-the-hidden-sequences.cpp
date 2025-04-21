class Solution {
public:
    int numberOfArrays(vector<int>& nums, int lower, int upper) {
        long long cur = 0;
        long long mini = 0;
        long long maxi = 0;
        for(auto &x:nums){
            cur = cur + x;
            mini = min(mini,cur);
            maxi = max(maxi,cur);
        }

        long long l = lower-mini;
        long long r = upper-maxi;

        if(r-l+1<=0) return 0;

        return r-l+1;
    }
};