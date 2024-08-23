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
        vector<vector<ll>>dp(n+1,vector<ll>(2,-1));
        return fun(nums,0,1,dp);
    }
};