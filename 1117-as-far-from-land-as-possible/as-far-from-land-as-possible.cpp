class Solution {
public:
    vector<vector<int>>dirs={{0,-1},{-1,0},{0,1},{1,0}};

    bool isValid(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==0) return true;
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid.size();
        vector<vector<int>>vis = grid;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }

        if(!q.empty() && q.size()==n*n) return -1;

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i=0;i<size;i++){
                auto p = q.front();
                q.pop();

                for(auto &dir:dirs){
                    int _i = dir[0] + p.first;
                    int _j = dir[1] + p.second;

                    if(isValid(grid,_i,_j,n,m) && vis[_i][_j]==0){
                        q.push({_i,_j});
                        vis[_i][_j] = 1;
                    }
                }

            }
        }

        return level-1;
    }
};