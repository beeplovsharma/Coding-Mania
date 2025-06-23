class Solution {
public:
    int fun(vector<int>& nums,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = -1e9;

        for(int k=i;k<=j;k++){
            int cost = (nums[i-1]*nums[k]*nums[j+1]) + fun(nums,i,k-1,dp) + fun(nums,k+1,j,dp);

            maxi = max(maxi,cost);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        int i=1, j=n-2;

        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(nums,i,j,dp);
    }
};