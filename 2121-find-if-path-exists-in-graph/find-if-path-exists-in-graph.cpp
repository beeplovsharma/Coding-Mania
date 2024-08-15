class Solution {
public:
    void BFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        queue<int>q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto x:adj[u]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n+1,false);
        queue<int>q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto x:adj[u]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        
        if(visited[destination]==false) return false;

        return true;
    }
};