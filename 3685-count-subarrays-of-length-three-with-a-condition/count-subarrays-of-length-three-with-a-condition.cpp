class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i+2<n; i++) {
            float sum = nums[i]+nums[i+2];
            float half = nums[i+1]/2.0;

            if(sum==half) cnt++;
        }
        return cnt;
    }
};
