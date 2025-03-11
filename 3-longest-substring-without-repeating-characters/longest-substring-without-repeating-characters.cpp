class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n = s.size();
        map<char,int>mp;
        int maxi = INT_MIN;
        while(j<n){
            mp[s[j]]++;

            while(i<=j && mp.size()!=j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi==INT_MIN ? 0:maxi;
    }
};