class Solution {
public:
vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) 
            return;

        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,0);

        unordered_map<int,vector<int>>mp;
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];

            Union(u,v);
        }

        for(int i=0;i<n;i++){
            int pu = find(i);
            mp[pu].push_back(i);
        }

        vector<int>countOfNodes;
        vector<int>prefix;
        long long ans = 0;
        int remaining = n;
        for(auto &x:mp){
            ans += x.second.size() * 1LL * (remaining - x.second.size());
            remaining -= x.second.size();
        }
        return ans;

    }
};