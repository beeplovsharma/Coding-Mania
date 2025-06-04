class Solution {
public:
    void solve(vector<string>&grid,int row,vector<bool>&cols,vector<bool>&mdiag,vector<bool>&rdiag,vector<vector<string>>&ans){
        if(row==grid.size()){
            ans.push_back(grid);
            return;
        }
        
        int n = cols.size();
        for(int col=0;col<n;col++){
            if(cols[col]==false && mdiag[row+col]==false && rdiag[row-col+n-1]==false){
                grid[row][col]='Q';
                cols[col]=1;
                mdiag[row+col]=1;
                rdiag[row-col+n-1]=1;
                solve(grid,row+1,cols,mdiag,rdiag,ans);
                grid[row][col]='.';
                cols[col]=0;
                mdiag[row+col]=0;
                rdiag[row-col+n-1]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool>cols(n,0);
        vector<bool>mdiag(2*n-1,0);
        vector<bool>rdiag(2*n+1,0);
        vector<string>grid(n, string(n, '.'));
        vector<vector<string>>ans;

        solve(grid,0,cols,mdiag,rdiag,ans);
        
        return ans;
    }
};