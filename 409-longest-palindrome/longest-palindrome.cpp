class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        map<char,int>mp;
        int cnt = 0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;

            if(mp[s[i]]==2){
                cnt+=2;
                mp.erase(s[i]);
            }
        }

        cnt = mp.size()==0 ? cnt : cnt+1;

        return cnt;
    }
};