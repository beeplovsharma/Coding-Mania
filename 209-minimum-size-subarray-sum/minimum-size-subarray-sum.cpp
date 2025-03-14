class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        int sum = 0;
        int mini = INT_MAX;
        while(j<n){
            sum+=nums[j];

            while(i<=j && sum>=k){
                mini=min(mini,j-i+1);
                sum-=nums[i];
                i++;
            }

            j++;
        }
        return mini==INT_MAX ? 0 : mini;
    }
};