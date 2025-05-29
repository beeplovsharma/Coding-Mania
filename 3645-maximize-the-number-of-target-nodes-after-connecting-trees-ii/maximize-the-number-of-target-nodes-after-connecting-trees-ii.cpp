class Solution {
public:
    int BFS(vector<vector<int>> &adj, int n, vector<bool>& isEven) {
        queue<pair<int,int>> q;
        q.push({0, 0});
        vector<bool> vis(n, 0);
        vis[0] = true;
        isEven[0] = true;

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level % 2 == 0) {
                cnt++;
                isEven[node] = true;
            }

            for (auto& v : adj[node]) {
                if (!vis[v]) {
                    q.push({v, level + 1});
                    vis[v] = true;
                }
            }
        }

        return cnt;
    }

    int findEvenPlaces(vector<vector<int>>& edges, vector<bool>& isEven) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return BFS(adj, n, isEven);
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<bool> isEven(n, false);
        
        int evenCountForT1 = findEvenPlaces(edges1, isEven);
        int oddCountForT1 = n-evenCountForT1;

        vector<bool> isOdd(m,false);
        int evenCountForT2 = findEvenPlaces(edges2, isOdd);
        int oddCountForT2 = m - evenCountForT2;
        int maxi = max(evenCountForT2,oddCountForT2);

        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            if(isEven[i]){
                ans[i] = evenCountForT1+maxi;
            }else{
                ans[i] = oddCountForT1+maxi;
            }
        }

        return ans;
    }
};
