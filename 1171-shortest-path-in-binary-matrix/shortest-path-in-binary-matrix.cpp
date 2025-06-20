class Solution {
public:
    typedef pair<pair<int,int>,int> P;
    vector<vector<int>> dirs = {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    bool isValid(vector<vector<int>>&grid,int i,int j,int n){
        return (i>=0 && i<n && j>=0 && j<n && !grid[i][j]);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<P>q;
        q.push({{0,0},1});
        grid[0][0]=1;

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int level = q.front().second;
            q.pop();

            if(i==n-1 && j==n-1) return level;

            for(auto &dir:dirs){
                int _i = i+dir[0];
                int _j = j+dir[1];

                if(isValid(grid,_i,_j,n)){
                    q.push({{_i,_j},level+1});
                    grid[_i][_j]=1;
                }
            }
        }

        return -1;
    }
};