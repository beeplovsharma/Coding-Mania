class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>ans(n,0);
        int xorr = 0;
        for(int i=0;i<n;i++){
            xorr = xorr^(i==0 ? 0 : ans[i-1]);
            ans[i] = xorr^pref[i];
        }
        return ans;
    }
};