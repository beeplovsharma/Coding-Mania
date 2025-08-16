class Solution {
public:
    int dp[101][101];
    int fun(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int down = 0;
        if(i+1<n && grid[i+1][j]!=1) down = fun(grid,i+1,j,n,m);
        int right = 0;
        if(j+1<m && grid[i][j+1]!=1) right = fun(grid,i,j+1,n,m);

        return dp[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]) return 0;
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return fun(grid,0,0,n,m);
    }
};