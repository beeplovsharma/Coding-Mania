class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            char c = board[row][col];
            if (c == '.') continue;
            
            // Check row
            for (int i = 0; i < 9; i++) {
                if (i != col && board[row][i] == c) return false;
            }
            
            // Check column
            for (int i = 0; i < 9; i++) {
                if (i != row && board[i][col] == c) return false;
            }
            
            // Check 3x3 sub-box
            int boxRowStart = 3 * (row / 3);
            int boxColStart = 3 * (col / 3);
            for (int i = boxRowStart; i < boxRowStart + 3; i++) {
                for (int j = boxColStart; j < boxColStart + 3; j++) {
                    if ((i != row || j != col) && board[i][j] == c) return false;
                }
            }
        }
    }
    return true;
    }
};