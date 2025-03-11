class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        int zeros = 0;
        int maxi = INT_MIN;
        while(j<n){
            if(nums[j]==0) zeros++;

            while(i<=j && zeros>k){
                if(nums[i]==0) zeros--;
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};