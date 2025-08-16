class Solution {
public:
    typedef long long ll;
    int dp[201][201];
    ll fun(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i>=n || j>=m) return INT_MAX;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        ll down = grid[i][j] + fun(grid,i+1,j,n,m);
        ll right = grid[i][j] + fun(grid,i,j+1,n,m);

        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return fun(grid,0,0,n,m);
    }
};