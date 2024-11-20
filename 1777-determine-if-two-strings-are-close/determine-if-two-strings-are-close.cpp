class Solution {
public:
    vector<int> cntAlpha(string s){
        map<char,int>mp;
        for(auto c:s){
            mp[c]++;
        }

        vector<int>v;
        for(auto x:mp){
            v.push_back(x.second);
        }
        return v;
    }
    bool closeStrings(string word1, string word2) {
        int n = word1.size(),m=word2.size();
        if(n!=m) return false;

        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        if(word1==word2) return true;

        set<char>st;
        for(auto c:word1){
            st.insert(c);
        }

        for(auto c:word2){
            if(st.find(c)==st.end()) return false;
        }

        vector<int>v1,v2;
        v1 = cntAlpha(word1);
        v2 = cntAlpha(word2);

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        if(v1.size()!=v2.size()) return false;

        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }

        return true;
    }
};