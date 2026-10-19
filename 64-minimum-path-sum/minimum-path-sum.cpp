class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int fun(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int right = fun(grid,i,j+1);
        int down = fun(grid,i+1,j);

        int best = min(right,down);
        if(best==INT_MAX) return INT_MAX;
        return dp[i][j] = grid[i][j] + best;
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return fun(grid,0,0);
    }
};