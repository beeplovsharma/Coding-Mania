class Solution {
public:
    int leftfun(vector<int>& nums, int target){
        int low=0,high = nums.size()-1;
        int left_most = -1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(nums[mid]==target){
                left_most = mid;
                high = mid-1;
            }
            else if(target<nums[mid]) high = mid-1;
            else low = mid+1;
        }
        return left_most;
    }
    int rightfun(vector<int>& nums, int target){
        int low=0,high = nums.size()-1;
        int right_most = -1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(nums[mid]==target){
                right_most = mid;
                low = mid+1;
            }
            else if(target<nums[mid]) high = mid-1;
            else low = mid+1;
        }
        return right_most;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftfun(nums,target);
        int right = rightfun(nums,target);

        return {left,right};
    }
};