class Solution {
public:
    vector<int>dp;
    int fun(vector<int>& cost, int ind){
        if(ind==0 || ind==1) return cost[ind];

        if(dp[ind]!=-1) return dp[ind];

        return dp[ind] = cost[ind] + min(fun(cost,ind-1),fun(cost,ind-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n,-1);
        return min(fun(cost,n-1),fun(cost,n-2));
    }
};