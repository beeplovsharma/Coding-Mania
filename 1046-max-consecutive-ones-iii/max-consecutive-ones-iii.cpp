class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int n = nums.size(), maxLen = 0;
        // for(int i=0;i<n;i++){
        //     int zero = 0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==0) zero++;

        //         if(zero<=k){
        //             maxLen = max(maxLen,j-i+1);
        //         }
        //         else break;
        //     }
        // }

        // return maxLen;

        int l=0,r=0,n=nums.size();
        int maxLen = 0,zero=0;
        while(r<n){
            if(nums[r]==0) zero++;
            
            while(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
        
    }
};