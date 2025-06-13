class Solution {
public:
    bool feasible(vector<int>& nums, int p, int k){
        int cnt = 0;
        int n = nums.size();
        for(int i=1;i<n;){
            if(abs(nums[i]-nums[i-1])<=k) {
                cnt++;
                i+=2;
            }else{
                i++;
            }

            if(cnt>=p) return true;
        }

        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lo = 0, hi = nums.back();

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(feasible(nums,p,mid)) hi=mid;
            else lo = mid+1;
        }

        if(feasible(nums,p,lo)) return lo;
        if(feasible(nums,p,hi)) return hi;

        return 0;
    }
};