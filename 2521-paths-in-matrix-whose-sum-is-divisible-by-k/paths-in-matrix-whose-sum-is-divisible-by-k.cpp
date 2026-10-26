class Solution {
public:
    int n,m;
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>>dp;

    int fun(vector<vector<int>>& grid, int i, int j, int rem, int k){
        if(i<0 || i>=n || j<0 || j>=m) return 0;

        if(i==n-1 && j==m-1) return (rem + grid[i][j]) % k==0;

        if(dp[i][j][rem]!=-1) return dp[i][j][rem];


        int right = fun(grid,i,j+1,(rem + grid[i][j]) % k,k);
        int down = fun(grid,i+1,j,(rem + grid[i][j]) % k,k);

        return dp[i][j][rem] = (right + down) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n,vector<vector<int>>(m,vector<int>(k, -1)));

        return fun(grid,0,0,0,k);
    }
};