class Solution {
public:
    void DFS(vector<int>adj[],int u,vector<bool>&vis){
        vis[u]=true;

        for(auto &v:adj[u]){
            if(!vis[v]){
                DFS(adj,v,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int>adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                DFS(adj,i,vis);
                cnt++;
            }
        }

        return cnt;
    }
};