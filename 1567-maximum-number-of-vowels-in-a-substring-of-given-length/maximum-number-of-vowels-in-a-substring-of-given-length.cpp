class Solution {
public:
    bool checkVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int cnt = 0, maxx = 0;
        int i=0,j=0;
        int n = s.size();
        while(j<n){
            if(checkVowel(s[j])) cnt++;

            if(j-i+1 == k){
                maxx = max(maxx,cnt);
                if(checkVowel(s[i])) cnt--;
                i++;
            }
            j++;
        }

        return maxx;
    }
};