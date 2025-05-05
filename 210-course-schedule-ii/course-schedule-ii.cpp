class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int>adj[V];
        vector<int>indeg(V,0);
        for(auto &pre:prerequisites){
            int u = pre[1];
            int v = pre[0];

            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();

            for(auto &v:adj[curr]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        if(ans.size()==V) return ans;

        return {};
    }
};