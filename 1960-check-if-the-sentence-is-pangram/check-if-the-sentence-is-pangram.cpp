class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<char>v(26,0);

        for(auto ch:sentence){
            v[ch-'a']++;
        }

        for(int i=0;i<26;i++){
            if(v[i]==0) return false;
        }

        return true;
    }
};