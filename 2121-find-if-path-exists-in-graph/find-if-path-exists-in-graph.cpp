class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> adj;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if(vis[destination]==true) return true;

            for (auto x : adj[node]) {

                if (!vis[x]) {
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        return false;
    }
};