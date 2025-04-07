class Solution {
public:
    bool fun(vector<int>& nums,int ind,int tar,vector<vector<int>>&dp){
        if(tar==0) return true;
        if(tar<0 || ind==nums.size()) return false;
        
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        
        bool pick = fun(nums,ind+1,tar-nums[ind],dp);
        bool notPick = fun(nums,ind+1,tar,dp);

        return dp[ind][tar] = (pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totsum = 0;
        for(auto &x:nums) totsum+=x;
        if(totsum%2!=0) return false;
        int target = totsum/2;

        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return fun(nums,0,target,dp);
    }
};