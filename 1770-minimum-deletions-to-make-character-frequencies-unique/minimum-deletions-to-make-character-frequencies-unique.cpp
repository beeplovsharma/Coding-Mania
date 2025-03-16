class Solution {
public:
    int minDeletions(string s) {
        map<char,int>mp;
        set<int>st;

        for(auto &c:s){
            mp[c]++;
        }
        int cnt = 0;
        for(auto &it:mp){

            while(it.second>0 && st.find(it.second)!=st.end()){
                it.second--;
                cnt++;
            }
            st.insert(it.second);
        }

        return cnt;
    }
};