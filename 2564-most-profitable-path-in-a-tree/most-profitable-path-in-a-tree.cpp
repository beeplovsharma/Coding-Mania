class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;

    bool DFSBob(int curr, int t, vector<bool>& visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if (curr == 0) return true;  // Reached root

        for (auto &ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                if (DFSBob(ngbr, t + 1, visited)) return true;
            }
        }

        bobMap.erase(curr);  // Remove if Bob's path doesn't reach root
        return false;
    }

    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
        visited[curr] = true;

        if (bobMap.find(curr) == bobMap.end() || t < bobMap[curr]) {
            income += amount[curr];  // Alice takes full amount
        } else if (t == bobMap[curr]) {
            income += amount[curr] / 2;  // Alice gets half
        }

        bool isLeaf = (curr != 0 && adj[curr].size() == 1);  // Correct leaf condition
        if (isLeaf) {
            aliceIncome = max(aliceIncome, income);
        }

        for (auto &ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                DFSAlice(ngbr, t + 1, income, visited, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        aliceIncome = INT_MIN;

        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        DFSBob(bob, 0, visited);  // Bob's path determination

        visited.assign(n, false);
        DFSAlice(0, 0, 0, visited, amount);  // Alice's DFS

        return aliceIncome;
    }
};
