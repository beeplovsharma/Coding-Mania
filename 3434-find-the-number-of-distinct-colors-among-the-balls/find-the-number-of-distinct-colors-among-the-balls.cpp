class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>mp;
        map<int,int>bc;

        vector<int>ans;

        for(auto q:queries){
            int ball = q[0];
            int color = q[1];

            if(bc.find(ball)!=bc.end()){
                int prev_color = bc[ball];
                mp[prev_color]--;
                if(mp[prev_color]<=0) mp.erase(prev_color);
            }

            bc[ball]=color;
            mp[color]++;

            ans.push_back(mp.size());
        }

        return ans;
    }
};