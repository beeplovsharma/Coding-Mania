class Solution {
public:
    bool checkDup(vector<int>&hash){
        bool flag = false;
        for(int i=0;i<256;i++){
            if(hash[i]>1) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,0);
        int n = s.size();
        int i=0,j=0;
        int maxi = 0;
        while(j<n){
            hash[s[j]]++;

            while(i<n && checkDup(hash)){
                hash[s[i]]--;
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};