class Solution {
public:

    int fun(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        if(i>=0 && j>=0 && mat[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = fun(i-1,j,mat,dp);
        int left = fun(i,j-1,mat,dp);

        return dp[i][j] = up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // return fun(n-1,m-1,obstacleGrid,dp);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>=0 && j>=0 && obstacleGrid[i][j]==1) dp[i][j] = 0;

                    
                else if(i==0 && j==0){
                    dp[i][j] = 1;
                }

                else{
                    int up = 0;
                    if(i-1>=0) 
                        up = dp[i-1][j];

                    int left = 0;
                    if(j-1>=0)
                        left = dp[i][j-1];

                    dp[i][j] = up+left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};