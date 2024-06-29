class Solution {
public:
    int solve(vector<int>& nums,int low ,int high, int target){
        if(low>high) return -1;
        int mid = (low+high)/2;
        if(nums[mid]==target) return mid;

        if(target<nums[mid]){
            return solve(nums,low,mid-1,target);
        }
        else{
            return solve(nums,mid+1,high,target);
        }
    }
    int search(vector<int>& nums, int target) {
        // int low = 0;
        // int high = nums.size()-1;

        // while(low<=high){
        //     int mid = (low+high)/2;
        //     if(nums[mid]==target) return mid;

        //     else if(target < nums[mid]) high = mid-1;
        //     else low = mid+1;
        // }

        // return -1;

        return solve(nums,0,nums.size()-1,target);
    }
};