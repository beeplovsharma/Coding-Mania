class Solution {
public:
    void DFS(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis,unordered_map<int,int>&nodeToComp,int &comp){
        vis[node]=1;
        nodeToComp[node]=comp;

        for(auto &v:adj[node]){
            if(!vis[v]){
                DFS(v,adj,vis,nodeToComp,comp);
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,int>nodeToComp;
        vector<bool>vis(n,0);
        int comp = 1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(i,adj,vis,nodeToComp,comp);
                comp++;
            }
        }

        vector<int>compAndScore(comp+1,pow(2,31)-1);
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int val = edge[2];

            int compp = nodeToComp[u];
            compAndScore[compp] &= val;
        }

        vector<int>ans;
        for(auto &q:query){
            int u = q[0];
            int v = q[1];

            if(nodeToComp[u]==nodeToComp[v]){
                int compp = nodeToComp[u];
                ans.push_back(compAndScore[compp]);
            }
            else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};