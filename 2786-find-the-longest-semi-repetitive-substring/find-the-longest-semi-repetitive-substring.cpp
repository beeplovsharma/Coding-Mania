class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        map<int,int>mp;
        int adj = 0;
        int maxi = INT_MIN;

        int i=0,j=0;
        int n = s.size();


        while(j<n){
            mp[s[j]]++;
            if(j>0 && s[j]==s[j-1]) adj++;

            if(adj<=1){
                maxi = max(maxi,j-i+1); 
                j++;
            }

            else if(adj>1){
                while(adj>1 && i<=j){
                    mp[s[i]]--;
                    if(i<n-1 && s[i]==s[i+1]) adj--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};