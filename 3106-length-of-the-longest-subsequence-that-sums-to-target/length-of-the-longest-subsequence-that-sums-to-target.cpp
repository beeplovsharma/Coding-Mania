class Solution {
public:
    int fun(vector<int>& nums,int ind, int tar,vector<vector<int>>&dp){
        if(tar<0) return -1e9;
        if(ind==nums.size()) return tar==0 ? 0 : -1e9;

        if(dp[ind][tar]!=-1) return dp[ind][tar];
        
        int skip = fun(nums,ind+1,tar,dp);
        int choose = choose = 1 + fun(nums,ind+1,tar-nums[ind],dp);

        return dp[ind][tar] = max(skip,choose);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans = fun(nums,0,target,dp);
        return ans<-1e8 ? -1 : ans;
    }
};