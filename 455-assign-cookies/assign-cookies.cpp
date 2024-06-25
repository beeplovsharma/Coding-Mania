class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int,int>mp;

        for(auto x:s){
            mp[x]++;
        }
        int cnt=0;
        for(int i=0;i<g.size();i++){
            auto it = mp.lower_bound(g[i]);
            if(it != mp.end()){
                cnt++;
                mp[it->first]--;
                if(mp[it->first]==0) mp.erase(it->first);
            }
        }
        return cnt;
    }
};