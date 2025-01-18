class Solution {
public:
    void DFS(int node,vector<int>adj[],int &nodeCount,int &edgeCount,vector<bool>&isVisited){
        isVisited[node]=true;
        nodeCount += 1;
        edgeCount += adj[node].size();
        for(auto nextNode:adj[node]){
            if(!isVisited[nextNode]){
                DFS(nextNode,adj,nodeCount,edgeCount,isVisited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<bool>isVisited(n,0);
        for(int i=0;i<n;i++){
            int nodeCount = 0, edgeCount = 0;
            if(isVisited[i]) continue;
            DFS(i,adj,nodeCount,edgeCount,isVisited);
            if(nodeCount * (nodeCount-1) == edgeCount) ans++;
        }
        return ans;
    }
};