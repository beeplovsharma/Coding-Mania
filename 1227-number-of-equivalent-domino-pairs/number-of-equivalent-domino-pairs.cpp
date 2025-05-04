class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(auto &x:dominoes){
            int a = min(x[0],x[1]);
            int b = max(x[0],x[1]);

            int key = 10*a+b;
            if(mp.count(key)) ans += mp[key];
            mp[key]++;

        }
        return ans;
    }
};