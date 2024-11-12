class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int row, int col,vector<vector<int>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        if (row >= 0 && row < m && col >= 0 && col < n 
            && grid[row][col] == '1' && !visited[row][col])
            return true;

        return false;
    }
    void DFS(vector<vector<char>>& grid, int row, int col,
             vector<vector<int>>& visited){
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;
        // Four possible directions for movement (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto dir : directions) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                if (isValid(grid, nrow, ncol, visited)) {
                    DFS(grid,nrow,ncol,visited);
                }
            }

    }
    void BFS(vector<vector<char>>& grid, int row, int col,
             vector<vector<int>>& visited) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        // Four possible directions for movement (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse the neighbours in the four valid directions
            for (auto dir : directions) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                if (isValid(grid, nrow, ncol, visited)) {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cnt = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    cnt++;
                    DFS(grid, row, col, visited);
                }
            }
        }

        return cnt;
    }
};