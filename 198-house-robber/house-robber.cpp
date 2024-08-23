class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            int steal = nums[ind];
            if(ind+2<=n) steal = nums[ind] + dp[ind+2];
            int notSteal = 0;
            if(ind<=n) notSteal = 0 + dp[ind+1];

            dp[ind] = max(steal,notSteal);
        }
        return dp[0];
    }
};