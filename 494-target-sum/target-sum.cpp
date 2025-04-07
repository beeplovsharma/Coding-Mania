class Solution {
public:
    int fun(vector<int>& nums, int ind ,int tar,unordered_map<string,int>&dp){
        if(ind==nums.size()){
            return tar==0;
        }

        string key = to_string(ind)+"_"+to_string(tar);
        if(dp.count(key)) return dp[key];

        int add = fun(nums,ind+1,tar+nums[ind],dp);
        int sub = fun(nums,ind+1,tar-nums[ind],dp);

        return dp[key] = (add+sub);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string,int>dp;
        return fun(nums,0,target,dp);
    }
};