class Solution {
public:
    int fun(vector<int>&nums,int ind,int tar,vector<vector<int>>&dp){
        if(tar==0) return 0;
        if(ind>=nums.size() || tar<0) return 1e9;

        if(dp[ind][tar]!=-1) return dp[ind][tar];

        int pick = 1 + fun(nums,ind,tar-nums[ind],dp);
        int notPick = fun(nums,ind+1,tar,dp);

        return dp[ind][tar] = min(pick,notPick);
    }
    int numSquares(int n) {
        vector<int>hash;
        for(int i=1;i*i<=n;i++){
            hash.push_back(i*i);
        }
        vector<vector<int>>dp(hash.size()+1,vector<int>(n+1,-1));
        return fun(hash,0,n,dp);
    }
};