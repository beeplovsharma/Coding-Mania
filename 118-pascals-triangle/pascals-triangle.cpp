class Solution {
public:
    vector<int> generateRow(int n){
        int ans = 1;
        vector<int>temp;
        temp.push_back(ans);
        for(int i=1;i<n;i++){
            ans = ans * (n-i);
            ans = ans / i;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int n = numRows;
        for(int i=1;i<=n;i++){
            vector<int>v;
            v = generateRow(i);
            ans.push_back(v);
        }
        return ans;
    }
};