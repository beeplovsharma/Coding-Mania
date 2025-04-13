class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>pref;
        int xorr = 0;
        for(int i=0;i<arr.size();i++){
            xorr ^= arr[i];
            pref.push_back(xorr);
        }

        vector<int>ans;
        for(auto &q:queries){
            int l = q[0];
            int r = q[1];

            int x = pref[r] ^ (l-1>=0 ? pref[l-1] : 0);
            ans.push_back(x);
        }
        return ans;
    }
};