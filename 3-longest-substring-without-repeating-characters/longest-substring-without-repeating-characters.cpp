class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            vector<int>hash(256);
            for(int j=i;j<s.size();j++){
                if(hash[s[j]]){
                    break;
                }
                
                else{
                    ans = max(ans,j-i+1);
                    hash[s[j]]=1;
                }
            }
        }
        return ans;
    }
};