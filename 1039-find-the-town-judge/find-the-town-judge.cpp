class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>in,out;
        for(auto t:trust){
            int u = t[0];
            int v = t[1];

            in[v]++;
            out[u]++;
        }

        for(int i=1;i<=n;i++){
            int temp = in[i]-out[i];
            if(temp==n-1) return i;
        }
        return -1;
    }
};