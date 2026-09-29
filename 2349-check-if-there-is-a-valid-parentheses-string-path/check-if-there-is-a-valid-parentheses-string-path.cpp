class Solution {
public:
    int n,m;
    vector<vector<vector<int>>>dp;
    bool fun(vector<vector<char>>& grid, int i, int j, int balance){
        if(i<0 || i>=n || j<0 || j>=m) return false;

        if(grid[i][j]=='(') balance++;
        else balance--;

        if(balance<0) return false;

        if(i==n-1 && j==m-1) return balance==0;

        if(dp[i][j][balance]!=-1) return dp[i][j][balance];

        bool right = fun(grid,i,j+1,balance); // right
        bool down = fun(grid,i+1,j,balance); // down

        return dp[i][j][balance] = right || down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n,vector<vector<int>>(m,vector<int>(n+m,-1)));

        if (grid[0][0] == ')')
            return false;

        if (grid[n-1][m-1] == '(')
            return false;

        // Path length must be even
        // if ((n + m - 1) % 2 != 0)
        //     return false;

        return fun(grid, 0, 0, 0);
    }
};