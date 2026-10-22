using ll = long long;
class Solution {
public:
    int n,m;
    const int MOD = 1e9 + 7;
    vector<vector<pair<ll,ll>>>dp;
    vector<vector<bool>>vis;
    pair<ll,ll> fun(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return make_pair(LLONG_MAX,LLONG_MIN);
        if(i==n-1 && j==m-1) return make_pair((ll)grid[i][j],(ll)grid[i][j]);

        if(vis[i][j]) return dp[i][j];
        
        vis[i][j] = true;

        auto [rmin,rmax] = fun(grid,i,j+1);
        auto [dmin,dmax] = fun(grid,i+1,j);

        ll bmin = min({rmin, dmin});
        ll bmax = max({rmax, dmax});

        if(bmin!=LLONG_MAX) bmin = bmin * 1LL * grid[i][j];
        if(bmax!=LLONG_MIN) bmax = bmax * 1LL * grid[i][j];

        if(grid[i][j]<0) swap(bmin,bmax);

        return dp[i][j] = make_pair(bmin,bmax);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.resize(n,vector<pair<ll,ll>>(m,make_pair(LLONG_MAX,LLONG_MIN)));
        vis.resize(n,vector<bool>(m,false));

        auto ans = fun(grid,0,0);

        if(ans.second < 0) return -1;

        return ans.second % MOD;
    }
};