class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int fun(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return INT_MAX;

        if(dp[i][j]!=INT_MAX) return dp[i][j];
        
        int ldiag = fun(grid,i-1,j-1);
        int up = fun(grid,i-1,j);
        int rdiag = fun(grid,i-1,j+1);

        int ans = min({up,ldiag,rdiag});

        if(ans == INT_MAX) ans = 0;

        return dp[i][j] = grid[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n,vector<int>(m,INT_MAX));

        int ans = INT_MAX;

        for(int j=0;j<m;j++){
            ans = min(ans,fun(grid,n-1,j));
        }

        return ans;
    }
};