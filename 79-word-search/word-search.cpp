class Solution {
public:
    vector<vector<int>>directions = {{-1,0},{1,0},{0,1},{0,-1}};
    int n,m;
    bool fun(vector<vector<char>>& board,int i,int j, string word,int idx){
        if(idx==word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='$') return false;
        if(board[i][j]!=word[idx]) return false;

        
        char ch = board[i][j];
        board[i][j] = '$';

        for(auto &dir : directions){
            int _i = i+dir[0];
            int _j = j+dir[1];

            if(fun(board,_i,_j,word,idx+1)) return true;
        }

        board[i][j] = ch;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(fun(board,i,j,word,0)) return true;
                }
            }
        }

        return false;
    }
};