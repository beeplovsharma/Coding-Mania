class Solution {
public:
    int fun(vector<int>& nums,int ind,int n,vector<int>&dp){
        if(ind>=n) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int steal = nums[ind] + fun(nums,ind+2,n,dp);
        int notSteal = 0 + fun(nums,ind+1,n,dp);

        return dp[ind] = max(steal,notSteal);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int>dp(n+1,-1);
        int firstAtt = fun(nums,0,n-1,dp);
        fill(dp.begin(), dp.end(), -1);
        int secondAtt = fun(nums,1,n,dp);

        return max(firstAtt,secondAtt);
    }
};