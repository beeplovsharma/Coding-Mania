class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int maxi = 0;

        while(j<n){
            if(nums[j]==0) k--;

            while(i<n && k<0){
                if(nums[i]==0) k++;
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};