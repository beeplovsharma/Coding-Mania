class Solution {
public:
    int getSum(vector<int>& nums){
        int sum = 0;
        for(auto &x:nums){
            sum += x;
        }
        return sum;
    }
    bool fun(vector<int>& nums,int ind,int tar,vector<vector<int>>&dp){
        if(tar==0) return true;
        if(tar<0 || ind==nums.size()) return false;

        if(dp[ind][tar]!=-1) return dp[ind][tar];

        bool notPick = fun(nums,ind+1,tar,dp);
        bool pick = fun(nums,ind+1,tar-nums[ind],dp);

        return dp[ind][tar] = (pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int totSum = getSum(nums);
        if(totSum%2!=0) return false;
        int tar = totSum/2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return fun(nums,0,tar,dp);
    }
};