class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = -1;
        int n = nums.size();
        int premin = 1e9;
        for(int i=0;i<n;i++){
            if(nums[i]<=premin) premin = nums[i];
            else maxi = max(maxi,nums[i]-premin);
        }

        return maxi;
    }
};