class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int fun(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return 0;

        if(grid[i][j]==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = fun(grid,i-1,j);
        int left = fun(grid,i,j-1);
        int diag = fun(grid,i-1,j-1);

        return dp[i][j] = 1 + min({up,left,diag});
    }

    int countSquares(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n,vector<int>(m,-1));

        int maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxSide += fun(grid, i, j);
            }
        }

        return maxSide;
    }
};