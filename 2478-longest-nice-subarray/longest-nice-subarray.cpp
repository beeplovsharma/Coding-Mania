class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        int i = 0, j = 0;
        int mask = 0;

        while (j < n) {
            
            while((mask&nums[j])){
                mask ^= nums[i];
                i++;
            }
            mask = (mask|nums[j]);
            maxi = max(maxi, j - i + 1); // Update max subarray length
            j++;
        }

        return maxi;
    }
};