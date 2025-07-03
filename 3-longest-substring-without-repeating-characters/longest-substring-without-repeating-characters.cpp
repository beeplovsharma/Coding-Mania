class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,0);
        int n = s.size();
        int i=0,j=0;
        int maxi = 0;
        while(j<n){
            hash[s[j]]++;

            while(i<n && hash[s[j]]>1){
                hash[s[i]]--;
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};