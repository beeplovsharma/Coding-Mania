class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<bool>&isVisited){
        isVisited[node]=1;

        for(auto it:adj[node]){
            if(!isVisited[it])
                dfs(it,adj,isVisited);
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        int cnt = 0;
        vector<bool>isVisited(n,0);

        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!isVisited[i]){
                dfs(i,adj,isVisited);
                cnt++;
            }
        }

        return cnt;
    }
};