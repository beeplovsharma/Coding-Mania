class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int fun(vector<vector<int>>& grid,int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int right = fun(grid,i,j+1);
        int down = fun(grid,i+1,j);

        return dp[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return fun(grid,0,0);
    }
};