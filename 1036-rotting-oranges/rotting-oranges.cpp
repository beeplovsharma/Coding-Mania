class Solution {
public:
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    bool isValid(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        return (i>=0 && i<n && j>=0 && j<m && !vis[i][j] && grid[i][j]==1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){     
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int minutes = 0;


        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int level = q.front().second;
            minutes = max(minutes,level);
            q.pop();

            for(auto &dir:dirs){
                int _i = i+dir[0];
                int _j = j+dir[1];

                if(isValid(_i,_j,vis,grid)){
                    q.push({{_i,_j},level+1});
                    vis[_i][_j]=true;
                    fresh--;
                }
            }
        }

        return fresh>0 ? -1 : minutes;
    }
};