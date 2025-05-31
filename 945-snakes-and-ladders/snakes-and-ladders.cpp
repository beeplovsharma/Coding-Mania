class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int MAX = n*n;
        vector<bool>vis(MAX+1,false);
        queue<pair<int,int>>q;
        q.push({1,0});
        vis[1]=true;

        while(!q.empty()){
            int node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(node==MAX){
                return level;
            }

            for(int i=1;i<=6;i++){
                int next = node+i;
                if(next>MAX) break;
                int top_row = (next-1)/n;
                int r = n-top_row-1;
                int c = (next-1)%n;
                if((n - r) % 2 == 0) c = n - c - 1;
                int dest = board[r][c] == -1 ? next : board[r][c];
                if(!vis[dest]){
                    q.push({dest, level+1});
                    vis[dest] = true;
                }
            }

        }
        return -1;
    }
};