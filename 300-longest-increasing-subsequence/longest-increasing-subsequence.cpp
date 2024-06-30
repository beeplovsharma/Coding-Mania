class Solution {
public:
    int fun(vector<int>& arr, int ind, int prev,vector<vector<int>>&dp) {
        if(ind == arr.size()) return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int notTake = 0 + fun(arr,ind+1,prev,dp);
        int take = 0;
        if(prev==-1 || arr[ind]>arr[prev]){
            take = 1 + fun(arr,ind+1,ind,dp);
        }

        return dp[ind][prev+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(nums,0,-1,dp);
    }
};