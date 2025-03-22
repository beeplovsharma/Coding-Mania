class Solution {
public:
    void DFS(int node,unordered_map<int,vector<int>>adj,vector<bool>&vis,int &cnode,int &cedge){
        vis[node]=true;
        cnode+=1;
        cedge+=adj[node].size();
        for(auto &ne:adj[node]){
            if(!vis[ne]){
                DFS(ne,adj,vis,cnode,cedge);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int comp = 0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnode=0,cedge=0;
                DFS(i,adj,vis,cnode,cedge);
                if(cnode*(cnode-1) == cedge) comp++;
            }
        }

        return comp;
    }
};