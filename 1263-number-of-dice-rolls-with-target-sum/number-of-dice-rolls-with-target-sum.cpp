class Solution {
public:
    const int MOD = 1e9 + 7;

    int fun(int dice, int tar, int k,vector<vector<int>>&dp) {
        if(dice == 0 && tar == 0) return 1;
        if(dice==0 || tar<0) return 0;

        if(dp[dice][tar]!=-1) return dp[dice][tar];
        
        int count = 0;
        for(int face=1;face<=k;face++){
            count = (count + fun(dice-1,tar-face,k,dp))%MOD;
        }

        return dp[dice][tar] = count;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return fun(n, target, k,dp);
    }

};