class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str = "";
        int m = word1.size(), n = word2.size();
        int loop = max(m,n);
        int c1 = 0, c2 = 0;
        for(int i=0;i<loop;i++){
            if(c1<m){
                str.push_back(word1[c1]);
                c1++;
            }
            if(c2<n){
                str.push_back(word2[c2]);
                c2++;
            }
        }

        return str;
    }
};