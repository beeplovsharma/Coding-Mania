class Solution {
public:
    bool isRightPlaceForQueen(vector<string>&chess,int row,int col,int n){
        //Check Vertically
        for(int i=row-1,j=col;i>=0;i--){
            if(chess[i][j]=='Q') return false;
        }

        //Check Left-Diagonal
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(chess[i][j]=='Q') return false;
        }

        //Check Right-Diagonal
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(chess[i][j]=='Q') return false;
        }

        return true;
    }
    void fun(int row,vector<string>chess,vector<vector<string>>&ans,int n){
        if(row==n){
            ans.push_back(chess);
            return;
        }

        for(int col=0;col<n;col++){
            if(isRightPlaceForQueen(chess,row,col,n)){
                chess[row][col] = 'Q';
                fun(row+1,chess,ans,n);
                chess[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        vector<vector<string>>ans;
        int row = 0;
        fun(row,chess,ans,n);
        return ans;
    }
};