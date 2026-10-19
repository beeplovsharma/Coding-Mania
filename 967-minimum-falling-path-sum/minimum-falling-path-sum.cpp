class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int fun(vector<vector<int>>& grid,int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return INT_MAX;
        if(i==n-1) return grid[i][j];

        if(dp[i][j]!=INT_MAX) return dp[i][j];

        int ldown = fun(grid,i+1,j-1);
        int down = fun(grid,i+1,j);
        int rdown = fun(grid,i+1,j+1);
        
        int msf = min({ldown,down,rdown});
        
        if(msf==INT_MAX) return INT_MAX;
        
        return dp[i][j] = grid[i][j] + msf;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int mini = INT_MAX;
        
        dp.resize(n,vector<int>(m,INT_MAX));
        
        for(int j=0;j<m;j++){
            mini = min(mini, fun(grid,0,j));
        }
        
        return mini;
    }
};