class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0,j=0;
        unordered_map<char,int>mp;
        int maxi = 0;
        while(j<n){
            mp[s[j]]++;

            while(i<n && mp[s[j]]>1){
                mp[s[i]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};