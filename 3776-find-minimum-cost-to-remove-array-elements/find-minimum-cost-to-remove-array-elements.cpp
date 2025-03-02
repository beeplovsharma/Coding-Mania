class Solution {
public:

    int fun(vector<int>& nums,int prev,int ind,vector<vector<int>>&dp){
        if(ind==nums.size()) return nums[prev];
        if(ind==nums.size()-1) return max(nums[prev],nums[ind]);

        if(dp[prev][ind]!=-1) return dp[prev][ind];

        int op1 = max(nums[prev],nums[ind]) + fun(nums,ind+1,ind+2,dp);
        int op2 = max(nums[prev],nums[ind+1]) + fun(nums,ind,ind+2,dp);
        int op3 = max(nums[ind],nums[ind+1]) + fun(nums,prev,ind+2,dp);

        return dp[prev][ind] = min(op1,min(op2,op3));
    }

    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(nums,0,1,dp);
    }
};