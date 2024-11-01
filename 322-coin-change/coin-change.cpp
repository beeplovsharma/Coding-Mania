class Solution {
public:
    int fun(vector<int>& nums,int ind, int amount,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(ind==0){
            if(amount%nums[0]==0) return (amount/nums[0]);
            return 1e9;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int notTake = fun(nums,ind-1,amount,dp);
        int take = 1e9;
        if(nums[ind]<=amount){
            take = 1 + fun(nums,ind,amount-nums[ind],dp);
        }


        return dp[ind][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& nums, int amt) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(1e4+1,-1));

        for(int T=0;T<=1e4;T++){
            if(T%nums[0]==0) dp[0][T] = T/nums[0];
            else dp[0][T] = 1e9;
        }
        for(int i=0;i<n;i++) dp[i][0] = 0;

        for(int ind=1;ind<n;ind++){
            for(int amount=1;amount<=1e4;amount++){
                int notTake = dp[ind-1][amount];
                int take = 1e9;
                if(nums[ind]<=amount){
                    take = 1 + dp[ind][amount-nums[ind]];
        }


            dp[ind][amount] = min(take,notTake);
            }
        }

        int ans = dp[n-1][amt];
        if(ans==1e9) return -1;
        else return ans;
    }
};