class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int tar=1;tar<=amount;tar++){
                int pick = 1e9,notPick=1e9;
                if(tar-coins[ind]>=0) pick = 1 + dp[ind][tar-coins[ind]];
                if(ind+1<n) notPick = dp[ind+1][tar];

                dp[ind][tar] = min(pick,notPick);
            }
        }

        int ans = dp[0][amount];
        return ans==1e9 ? -1 : ans;
    }
};