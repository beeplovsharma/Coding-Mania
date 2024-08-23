class Solution {
#define ll long long
public:
    ll fun(vector<int>& nums,int ind,int isEven,vector<vector<ll>>&dp){
        if(ind>=nums.size()) return 0;

        if(dp[ind][isEven]!=-1) return dp[ind][isEven];

        ll notpick = fun(nums,ind+1,isEven,dp);
        ll val = isEven ? nums[ind] : -nums[ind];
        ll pick = val + fun(nums,ind+1,!isEven,dp);

        return dp[ind][isEven] = max(pick,notpick);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>>dp(n+1,vector<ll>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int isEven = 0;isEven<2;isEven++){
                ll notpick = dp[ind+1][isEven];
                ll val = isEven ? nums[ind] : -nums[ind];
                ll pick = val + dp[ind+1][!isEven];

                dp[ind][isEven] = max(pick,notpick);
            }
        }
        return dp[0][1];
    }
};