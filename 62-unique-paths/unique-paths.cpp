class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int fun(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int right = fun(i,j+1);
        int down = fun(i+1,j);

        return dp[i][j] = right + down;
    }
    int uniquePaths(int N, int M) {
        n = N, m = M;
        dp.resize(n,vector<int>(m,-1));
        return fun(0,0);
    }
};