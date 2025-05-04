class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mp;
        int ans = 0;
        for(auto &x:dominoes){
            int a = min(x[0],x[1]);
            int b = max(x[0],x[1]);

            mp[{a,b}]++;
        }
        for(auto x:mp){
            int occ = x.second-1;
            ans += occ*(occ+1)/2;
        }
        return ans;
    }
};