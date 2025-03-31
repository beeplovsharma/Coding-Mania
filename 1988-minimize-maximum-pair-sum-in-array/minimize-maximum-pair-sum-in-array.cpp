class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int i=0,j=n-1;
        int maxi = INT_MIN;
        int sum = 0;
        while(i<j){
            sum = nums[i++]+nums[j--];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};