class Solution {
public:
    int N;
    int dp[101][2];
    int fun(vector<int>& nums,int ind,int adj){
        if(ind>=N) return 0;

        if(dp[ind][adj]!=-1) return dp[ind][adj];

        int skip = fun(nums,ind+1,0);
        int rob = 0;
        if(!adj) rob = nums[ind]+fun(nums,ind+1,1);

        return dp[ind][adj] = max(skip,rob);
    }
    int rob(vector<int>& nums) {
        N=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(nums,0,0);
    }
};