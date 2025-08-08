class Solution {
public:
    int N;
    vector<int> queen;             // queen[row] = col
    vector<string> way;           // current board (strings)
    vector<vector<string>> ans;   // all solutions

    bool check(int row, int col){
        for(int i = 0; i < row; ++i){
            int pcol = queen[i];
            if (col == pcol) return false; // same column
            if (abs(col - pcol) == abs(row - i)) return false; // diagonal
        }
        return true;
    }

    void rec(int level){
        if(level == N){
            ans.push_back(way);
            return;
        }
        for(int col = 0; col < N; ++col){
            if(check(level, col)){
                queen[level] = col;
                way[level][col] = 'Q';
                rec(level + 1);
                way[level][col] = '.';
                queen[level] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        queen.assign(N, -1);
        way.assign(N, string(N, '.'));
        ans.clear();

        rec(0);
        return ans;
    }
};
