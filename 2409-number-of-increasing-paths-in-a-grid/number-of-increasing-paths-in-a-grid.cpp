class Solution {
public:
    int n,m;
    const int MOD = 1e9 + 7;
    vector<vector<int>>dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>>dp;

    bool isSafe(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        int ans = 1;

        if(dp[i][j]!=-1) return dp[i][j];

        for(auto &dir : dirs){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(isSafe(i_,j_) && grid[i_][j_] > grid[i][j]){
                ans = (ans + dfs(grid,i_,j_)) % MOD;
            }
        }

        return dp[i][j] = ans % MOD;
    }

    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        n = grid.size();
        m = grid[0].size();
        dp.resize(n+1, vector<int>(m+1,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = (ans + dfs(grid,i,j)) % MOD;
            }
        }

        return ans % MOD;
    }
};