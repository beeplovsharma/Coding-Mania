class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        
        int p = 1;
        int i = 0, j = 0;
        int cnt = 0;
        int n = nums.size();

        while(j<n){
            p = p * nums[j];

            while(p>=k){
                p = p/nums[i];
                i++;
            }

            int wsize = (j-i+1);
            cnt+=wsize;
            j++;
        }
        return cnt;
    }
};