class Solution {
public:
    int fun(vector<int>& nums,int ind, int target,vector<int>&dp){
        if(ind>=nums.size()) return -1e9;
        if(ind==nums.size()-1) return 0;

        if(dp[ind]!=-1) return dp[ind];
 
        int maxJumps = -1e9;
        for(int jump=ind+1;jump<nums.size();jump++){
            int canJump = -1e9;
            if(abs(nums[jump]-nums[ind])<=target) canJump = 1+fun(nums,jump,target,dp);
            maxJumps = max(maxJumps,canJump); 
        }

        return dp[ind] = maxJumps;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = fun(nums,0,target,dp);
        return ans<=-1e8 ? -1 : ans;
    }
};