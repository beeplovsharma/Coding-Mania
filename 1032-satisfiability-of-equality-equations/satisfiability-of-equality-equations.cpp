class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if(x==parent[x]) return x;

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

    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i]=i;
        rank.resize(26,0);

        for(int i=0;i<n;i++){
            int p = equations[i][0]-'a';
            char q = equations[i][1];
            int r = equations[i][3]-'a';
            
            if(q=='='){
                Union(p,r);
            }
        }

        for(int i=0;i<n;i++){
            int p = equations[i][0]-'a';
            char q = equations[i][1];
            int r = equations[i][3]-'a';
            
            if(q=='!'){
                int pu = find(p);
                int pv = find(r);

                if(pu==pv) return false;
            }
        }

        return true;
    }
};