class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int i=0,j=0;
        int n = s.size();
        map<int,int>mp;
        int cnt = 0;
        while(j<n){
            mp[s[j]]++;
            
            while(i<=j && mp[s[j]]==k){
                cnt+=n-j;
                mp[s[i]]--;
                i++;
            }

            j++;
        }
        return cnt;
    }
};