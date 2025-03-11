class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int n = s.size();

        int cnt = 0;

        unordered_map<char,int>mp;
        while(j<n){
            if(s[j]=='b' || s[j]=='a' || s[j]=='c'){
                mp[s[j]]++;
            }

            while(i<=j && mp.size()==3){
                cnt+=n-j;
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }

            j++;
        }
        return cnt;
    }
};