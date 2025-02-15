class Solution {
public:
    int n,m,nonObs;
    vector<vector<int>>dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    int result;

    void backTrack(vector<vector<int>>& grid,int i,int j,int cnt){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1) return;
        if(grid[i][j]==2){
            if(nonObs==cnt)result++;
            return;
        }

        grid[i][j] = -1;

        for(auto &dir:dirs){
            int _i = dir[0] + i;
            int _j = dir[1] + j;

            backTrack(grid,_i,_j,cnt+1);
        }

        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(),m = grid[0].size(),nonObs=0,result=0;
        int x = -1,y = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 || grid[i][j]==1) nonObs++;
                if(grid[i][j]==1) x=i,y=j;
            }
        }
        backTrack(grid,x,y,0);
        return result;
    }
};