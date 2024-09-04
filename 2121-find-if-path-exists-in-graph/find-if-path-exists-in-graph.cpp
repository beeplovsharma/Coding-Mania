class Solution {
public:
    void BFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
        queue<int>q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge : edges){
           int u = edge[0];
           int v = edge[1];

           adj[u].push_back(v);
           adj[v].push_back(u);
        }

        vector<bool>visited(n,false);

        BFS(adj,source,visited);

        return visited[destination];
    }
};