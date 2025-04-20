class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(auto &x:answers) mp[x]++;
        int cnt = 0;
        for(auto &x:mp){
            int num = x.first;
            int freq = x.second;

            int times = ceil(freq / double(num+1));
            cnt += (num+1)*times;
        }

        return cnt;
    }
};