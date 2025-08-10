class Solution {
public:
    int N;
    int dp[1001][1001];
    int fun(int ind,int free,vector<int>& nums){
        if(ind==N) return 0;
        if(dp[ind][free]!=-1) return dp[ind][free];
        int buy = nums[ind] + fun(ind+1,ind+1,nums);
        int skip = INT_MAX;
        if(free>0){
            skip = fun(ind+1,free-1,nums);
        }

        return dp[ind][free] = min(buy,skip);
    }
    int minimumCoins(vector<int>& prices) {
        N = prices.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,prices);
    }
};