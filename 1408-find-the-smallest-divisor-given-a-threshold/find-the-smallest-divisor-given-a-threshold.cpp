class Solution {
public:
    bool feasible(vector<int>& nums, int threshold, int div){
        int n = nums.size();
        long long sum = 0;

        for(int i=0;i<n;i++){
            sum += ceil(nums[i]/(double)div);
            if(sum>threshold){
                return false;
            }
        }

        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(feasible(nums,threshold,mid)) hi = mid;
            else lo = mid;
        }
        if(feasible(nums,threshold,lo)) return lo;
        if(feasible(nums,threshold,hi)) return hi;

        return -1;
    }
};