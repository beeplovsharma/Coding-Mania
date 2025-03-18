class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int dup = 0;

        while (j < n) {
            int nn = nums[j];
            
            for (int k = 31; k >= 0; k--) {
                if (nn & (1 << k)) { // Checking if bit k is set
                    if (mp[k] > 0) dup++;  // If bit is already present, increment conflict count
                    mp[k]++;  // Increment count for bit position k
                }
            }

            while (dup > 0) { // Shrink window while there is conflict
                int nm = nums[i];
                for (int k = 31; k >= 0; k--) {
                    if (nm & (1 << k)) { // If bit is present
                        mp[k]--; 
                        if (mp[k] == 0) mp.erase(k);
                        else dup--;  // Reduce conflict count only if bit is still present
                    }
                }
                i++; // Shrink window
            }

            maxi = max(maxi, j - i + 1); // Update max subarray length
            j++;
        }

        return maxi;
    }
};