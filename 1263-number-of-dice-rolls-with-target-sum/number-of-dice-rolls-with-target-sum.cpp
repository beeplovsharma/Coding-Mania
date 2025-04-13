class Solution {
public:
    const int MOD = 1e9 + 7;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int dice=1;dice<=n;dice++){
            for(int tar=1;tar<=target;tar++){
                int count = 0;
                for(int face=1;face<=k;face++){
                    if(dice-1>=0 && tar-face>=0) count = (count + dp[dice-1][tar-face])%MOD;
                }

                dp[dice][tar] = count;
            }
        }
        return dp[n][target];
    }

};