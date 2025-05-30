class Solution {
public:
    void BFS(vector<int>& edges, int start, int col, vector<vector<int>>& dist) {
        int n = edges.size();
        queue<int> q;
        q.push(start);
        dist[start][col] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            int next = edges[node];
            if (next != -1 && dist[next][col] == -1) {
                dist[next][col] = dist[node][col] + 1;
                q.push(next);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> dist(n, vector<int>(2, -1));

        BFS(edges, node1, 0, dist);
        BFS(edges, node2, 1, dist);

        int answer = -1, minDist = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (dist[i][0] != -1 && dist[i][1] != -1) {
                int maxDist = max(dist[i][0], dist[i][1]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    answer = i;
                }
            }
        }
        return answer;
    }
};
