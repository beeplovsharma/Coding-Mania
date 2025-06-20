class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(nums[mid]<=target) lo=mid;
            else hi=mid-1;
        }

        if(nums[lo]==target) return lo;
        if(nums[hi]==target) return hi;

        return -1;
    }
};