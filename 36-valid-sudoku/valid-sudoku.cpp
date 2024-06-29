class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char c = board[row][col];
                if (c == '.')
                    continue;
                else {
                    for (int i = 0; i < 9; i++) {
                        if (i != col && board[row][i] == c)
                            return false;

                        if (i != row && board[i][col] == c)
                            return false;

                        if (board[3 * (row / 3) + i / 3]
                                 [3 * (col / 3) + i % 3] == c) {
                            if (3 * (row / 3) + i / 3 != row ||
                                3 * (col / 3) + i % 3 != col) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};