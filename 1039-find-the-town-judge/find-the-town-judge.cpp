class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1,0),out(n+1,0);
        for(auto &t:trust){
            int u = t[0];
            int v = t[1];

            out[u]++;
            in[v]++;
        }

        for(int i=1;i<=n;i++){
            if(in[i]-out[i] == n-1) return i;
        }

        return -1;
    }
};