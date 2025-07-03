class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            maxi = max(maxi,min(nums[i],nums[j])*(j-i));
            if(nums[i]<nums[j]) i++;
            else if(nums[i]>nums[j])j--;
            else i++,j--;
        }

        return maxi;
    }
};