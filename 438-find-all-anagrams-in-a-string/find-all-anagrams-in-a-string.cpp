class Solution {
public:
    bool check(vector<int>&hash){
        for(int i=0;i<hash.size();i++){
            if(hash[i]!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n = s.size(),m = p.size();
        int i=0,j=0;
        vector<int>hash(26,0);
        for(int i=0;i<p.size();i++) hash[p[i]-'a']++;
        while(j<n){
            hash[s[j]-'a']--;
            if(j-i+1<m){
                j++;
            }
            else{
                if(check(hash)) ans.push_back(i);
                hash[s[i]-'a']++;
                i++;
                j++;
            }
        }
        return ans;

    }
};