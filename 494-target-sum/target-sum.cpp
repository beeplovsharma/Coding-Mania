class Solution {
public:
    int fun(vector<int>& nums, int ind ,int tar,map<pair<int,int>,int>&dp){
        if(ind==nums.size()){
            return tar==0;
        }

        pair<int,int> key = {ind,tar};
        if(dp.count(key)) return dp[key];

        int add = fun(nums,ind+1,tar+nums[ind],dp);
        int sub = fun(nums,ind+1,tar-nums[ind],dp);

        return dp[key] = (add+sub);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int>,int>dp;
        return fun(nums,0,target,dp);
    }
};