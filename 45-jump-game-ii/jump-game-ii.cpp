class Solution {
public:
    int fun(vector<int>& nums,int ind,vector<int>&dp){
        if(ind==nums.size()-1) return 0;
        if(ind>=nums.size()) return 1e9;

        if(dp[ind]!=-1) return dp[ind];

        int minJumps = 1e9;
        for(int jump=1;jump<=nums[ind];jump++){
            minJumps = min(minJumps,1+fun(nums,ind+jump,dp));
        }
        return dp[ind] = minJumps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return fun(nums,0,dp);
    }
};