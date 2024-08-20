class Solution {
public:
// 2 Pointer
    string reverseWords(string s) {
        int i=0;
        int l=0, r=0;//hero hai hamare
        int n = s.size();

        // Reverse the string
        reverse(s.begin(),s.end());
        while(i<n){
            while(i<n && s[i]!=' '){
                s[r++] = s[i++];
            }

            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r] = ' ';
                r++;
                l=r;
            }
            i++;
        }

        string ans = s.substr(0,r-1);
        return ans;
    }
};