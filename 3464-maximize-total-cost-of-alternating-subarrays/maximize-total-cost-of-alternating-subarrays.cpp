class Solution {
    #define ll long long
public:
    ll solve(vector<int>& nums,int ind,int start,int sign,vector<vector<vector<ll>>>&dp){
        if(ind==nums.size()) return 0;

        if(dp[ind][start][sign]!=-1) return dp[ind][start][sign];

        ll ans = INT_MIN;
        if(start == 0){
            ans = max(ans,nums[ind]+solve(nums,ind+1,1,sign^1,dp));
        }
        else{
            if(sign==0){
                ans = max(ans,nums[ind]+solve(nums,ind+1,1,sign^1,dp)); //pick
                ans = max(ans,solve(nums,ind,0,0,dp)); //non-pick
            }
            else{
                ans = max(ans,-nums[ind]+solve(nums,ind+1,1,sign^1,dp)); //pick
                ans = max(ans,solve(nums,ind,0,0,dp)); //non-pick
            }
        }

        return dp[ind][start][sign] = ans;
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2,
        vector<ll>(2,-1)));
        return solve(nums,0,0,0,dp);
    }
};