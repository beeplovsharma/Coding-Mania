class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totSum = 0;
        for(auto it:nums) totSum += it;
        int tar = totSum-x;

        int i=0,j=0;
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        while(j<n){
            sum+=nums[j];
            while(i<=j && sum>tar){
                sum-=nums[i];
                i++;
            }
            if(sum==tar) maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi==INT_MIN ? -1 : (n-maxi);
    }
};