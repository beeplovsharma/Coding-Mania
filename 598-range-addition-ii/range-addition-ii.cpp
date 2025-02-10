class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size()==0) return m*n;

        int mini_i=INT_MAX,mini_j=INT_MAX;
        for(auto &op:ops){
            mini_i = min(mini_i,op[0]);
            mini_j = min(mini_j,op[1]);
        }

        return mini_i*mini_j;
    }
};