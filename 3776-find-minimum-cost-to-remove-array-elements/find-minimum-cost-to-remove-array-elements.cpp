class Solution {
public:
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        for(int prev=0;prev<n;prev++){
            dp[prev][n-1] = max(nums[prev],nums[n-1]);
            dp[prev][n] = nums[prev];
        }

        for(int prev=n-2;prev>=0;prev--){
            for(int ind=n-2;ind>=1;ind--){
                int op1 = max(nums[prev],nums[ind]) + dp[ind+1][ind+2];
                int op2 = max(nums[prev],nums[ind+1]) + dp[ind][ind+2];
                int op3 = max(nums[ind],nums[ind+1]) + dp[prev][ind+2];

                dp[prev][ind] = min(op1,min(op2,op3));
            }
        }
        return dp[0][1];
    }
};