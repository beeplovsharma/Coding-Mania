class Solution {
public:
    int lastNeg(vector<int>& nums){
        int lo = 0;
        int hi = nums.size()-1;

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(nums[mid]<0) lo=mid;
            else hi = mid;
        }
        
        if(nums[hi]<0) return hi;
        if(nums[lo]<0) return lo;
        return -1;
    }
    int firstPos(vector<int>& nums){
        int lo = 0;
        int hi = nums.size()-1;

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(nums[mid]>0) hi = mid;
            else lo = mid;
        }
        
        if(nums[lo]>0) return lo;
        if(nums[hi]>0) return hi;
        return nums.size();
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int neg_count = lastNeg(nums)+1;
        int pos_count = n-firstPos(nums);

        return max(neg_count,pos_count);
    }
};