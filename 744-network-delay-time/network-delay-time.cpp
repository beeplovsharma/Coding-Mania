class Solution {
public:
    typedef pair<int,int>P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>>adj(n+1);
        for(auto &e:times){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v,wt});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(n+1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k}); // {distance, node}

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto &[v, wt] : adj[u]) {
                if (d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int time = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            else time = max(time,dist[i]);
        }
        return time;
    }
};