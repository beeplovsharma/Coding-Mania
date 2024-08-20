class Solution {
public:
    bool checkAna(vector<int>&freq){
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>indices;

        vector<int>freq(26,0);
        // Counting Freq
        for(int i=0;i<p.size();i++){
            freq[p[i]-'a']++;
        }

        //Sliding Window
        int i=0,j=0;
        int n = s.size();
        int k = p.size(); //pattern size

        while(j<n){
            freq[s[j]-'a']--;

            if(j-i+1 == k){
                if(checkAna(freq)){
                    indices.push_back(i);
                }

                freq[s[i]-'a']++;
                i++;
            }

            j++;
        }

        return indices;
    }
};