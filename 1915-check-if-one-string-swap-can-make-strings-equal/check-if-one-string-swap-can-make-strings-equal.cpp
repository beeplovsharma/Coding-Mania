class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        vector<char>hash(26);

        int n=s1.size();

        for(int i=0;i<n;i++){
            hash[s1[i]-'a']++;
            hash[s2[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(hash[i]!=0) return false;
        }

        int notMatch = 0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) notMatch++;
        }

        if(notMatch<=2) return true;

        return false;
    }
};