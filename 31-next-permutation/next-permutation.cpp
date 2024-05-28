class Solution {
public:
    int findBreakPoint(vector<int>&nums){
        int n = nums.size();
        int ind = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }
        return ind;
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = findBreakPoint(nums);
        if(breakPoint==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        // Swapping break elem with the slightly greater elem
        for(int i=n-1;i>breakPoint;i--){
            if(nums[i]>nums[breakPoint]){
                swap(nums[i],nums[breakPoint]);
                break;
            }
        }

        // Ordering elements after breakpoint in ascending order
        reverse(nums.begin()+breakPoint+1,nums.end());
    }
};