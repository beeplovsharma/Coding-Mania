class Solution {
public:
    int fun(vector<int>& nums,int ind, int target,unordered_map<string,int>&dp){
        if(ind==0){
            if(target==0 && nums[ind]==0) return 2;
            if(nums[ind]==target || nums[ind]==-target) return 1;
            else return 0;
        }

        string key = to_string(ind)+"_"+to_string(target);
        if(dp.find(key)!=dp.end()) return dp[key];
        
        int add = fun(nums,ind-1,target+nums[ind],dp);
        int sub = fun(nums,ind-1,target-nums[ind],dp);

        return dp[key] = (add+sub);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string,int>dp;
        return fun(nums,n-1,target,dp);
    }
};