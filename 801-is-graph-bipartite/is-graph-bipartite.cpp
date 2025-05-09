class Solution {
public:
    bool DFS(vector<vector<int>>& adj,int cur,int curColor,vector<int>&color){
        color[cur]=curColor;
        for(auto &v:adj[cur]){
            if(color[v]==color[cur]) return false;
            if(color[v]==-1){
                if(DFS(adj,v,1-curColor,color)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(DFS(adj,i,1,color)==false) return false;
            }
        }

        return true;
    }
};