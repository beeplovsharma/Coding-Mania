class Solution {
public:
    int fun(vector<int>& cost, vector<int>& time,int ind,int wallsLeft,vector<vector<int>>&dp){
        if(wallsLeft<=0) return 0;
        if(ind==cost.size()) return 1e9; 

        if(dp[ind][wallsLeft]!=-1) return dp[ind][wallsLeft];

        int skip = fun(cost,time,ind+1,wallsLeft,dp);
        int paint = cost[ind] + fun(cost,time,ind+1,wallsLeft-1-time[ind],dp);

        return dp[ind][wallsLeft] = min(skip,paint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(cost,time,0,n,dp);
    }
};