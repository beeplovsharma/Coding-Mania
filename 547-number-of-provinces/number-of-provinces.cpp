class Solution {
public:
    void DFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int u){
        if(visited[u]==true) return;
        visited[u] = true;

        for(auto &v:adj[u]){
            if(!visited[v]){
                DFS(adj,visited,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>adj;
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+1 != j+1 && mat[i][j]==1) adj[i+1].push_back(j+1);
            }
        }
        vector<bool>visited(n,false);
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                cnt++;
                DFS(adj,visited,i);
            }
        }
        return cnt;
    }
};