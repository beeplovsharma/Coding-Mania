class Solution {
public:
    typedef long long ll;;
    bool feasible(vector<int>& nums, long long k,int mid){
        ll cnt = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            cnt += nums[i]/mid;
        }

        if(cnt>=k) return true;
        return false;
        
    }
    int maximumCandies(vector<int>& nums, long long k) {
        int lo = 1;
        int hi = 1e9;

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(feasible(nums,k,mid)) lo = mid;
            else hi = mid;
        }

        if(feasible(nums,k,hi)) return hi;
        if(feasible(nums,k,lo)) return lo;

        return 0;
    }
};