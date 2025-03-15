class Solution {
public:
    bool feasible(vector<int>& nums, int k, int mid){
        int prev = -1;
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if((nums[i]<=mid && (prev==-1 || i-prev>=2))){
                cnt++;
                prev=i;
            }
        }
        if(cnt>=k) return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int lo = 1, hi = *max_element(nums.begin(),nums.end());
        int n = nums.size();

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(feasible(nums,k,mid)) hi = mid;
            else lo = mid;
        }

        if(feasible(nums,k,lo)) return lo;
        if(feasible(nums,k,hi)) return hi;

        return -1;

    }
};