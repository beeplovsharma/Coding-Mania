class Solution {
public:
    bool isValid(vector<vector<int>>& image, int row, int col, vector<vector<bool>>& isVisited, int initialColor, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        if (row >= 0 && row < n && col >= 0 && col < m && 
            image[row][col] == initialColor && !isVisited[row][col] && 
            image[row][col] != newColor) {
            return true;
        }
        return false;
    }

    void DFS(vector<vector<int>>& image, int row, int col, int newColor, vector<vector<bool>>& isVisited, int initialColor) {
        isVisited[row][col] = true;
        image[row][col] = newColor;
        
        // Define four possible directions for traversal (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Perform DFS in each direction
        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            // Check if moving in the direction is valid
            if (isValid(image, newRow, newCol, isVisited, initialColor, newColor)) {
                DFS(image, newRow, newCol, newColor, isVisited, initialColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        int initialColor = image[sr][sc];
  
            DFS(image, sr, sc, newColor, isVisited, initialColor);
        return image;
    }
};
