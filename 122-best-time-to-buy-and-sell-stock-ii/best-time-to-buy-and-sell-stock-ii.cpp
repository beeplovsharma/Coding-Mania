class Solution {
public:
    int fun(vector<int>&arr,int ind,bool buy,vector<vector<int>>&dp){
        if(ind==arr.size()) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit = max(-arr[ind]+fun(arr,ind+1,false,dp),0+fun(arr,ind+1,true,dp));
        }
        else{
            profit = max(arr[ind]+fun(arr,ind+1,true,dp),0+fun(arr,ind+1,false,dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        bool buy = true;
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fun(prices,0,buy,dp);
    }
};