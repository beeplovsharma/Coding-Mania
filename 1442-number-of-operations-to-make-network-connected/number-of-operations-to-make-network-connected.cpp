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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
        rank.resize(n,0);

        int size = connections.size();
        if(size < n-1) return -1;

        int cnt = 0;
        for(auto &edge:connections){
            int u = edge[0];
            int v = edge[1];

            if(find(u)!=find(v)){
                Union(u,v);
                n--;
            }
        }

        return (n-1);
    }
};