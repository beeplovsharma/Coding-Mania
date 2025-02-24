class Solution {
public:
    bool feasible(vector<int>& nums, int k,int threshold){
        int cnt = 1;
        int sum = 0;

        for(auto &num:nums){
            sum+=num;

            if(sum>threshold){
                sum=num;
                cnt++;

                if(cnt>k) return false;
            }
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);

        while(hi-lo>1){
            int mid = hi+(lo-hi)/2;

            if(feasible(nums,k,mid)){
                hi = mid;
            }
            else lo=mid;
        }

        if(feasible(nums,k,lo)) return lo;
        if(feasible(nums,k,hi)) return hi;

        return -1;
    }
};