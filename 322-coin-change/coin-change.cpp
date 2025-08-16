class Solution {
public:
    int dp[13][10001];
    int fun(vector<int>& nums,int ind, int tar){
        if(ind==0){
            if(tar%nums[ind]==0) return tar/nums[ind];
            else return 1e9;
        }

        if(dp[ind][tar]!=-1) return dp[ind][tar];

        int skip = fun(nums,ind-1,tar);
        int choose = 1e9;
        if(tar-nums[ind]>=0) choose = 1+fun(nums,ind,tar-nums[ind]);

        return dp[ind][tar] = min(skip,choose);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int n = coins.size();
        int ans = fun(coins,n-1,amount);
        return ans>=1e9 ? -1 : ans;
    }
};