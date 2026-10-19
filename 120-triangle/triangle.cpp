class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int fun(vector<vector<int>>& tri, int i, int j){
        if(i<0 || i>=n || j<0 || j>=tri[i].size()) return INT_MAX;
        if(i==n-1) return tri[i][j];

        if(dp[i][j]!=INT_MAX) return dp[i][j];
        
        int dleft = fun(tri,i+1,j);
        int dright = fun(tri,i+1,j+1);

        int mini = min(dleft,dright);

        if(mini==INT_MAX) return INT_MAX;

        return dp[i][j] = tri[i][j] + mini;
    }

    int minimumTotal(vector<vector<int>>& tri) {
        n = tri.size();
        m = tri[n-1].size();
        dp.resize(n,vector<int>(m,INT_MAX));
        return fun(tri,0,0);
    }
};