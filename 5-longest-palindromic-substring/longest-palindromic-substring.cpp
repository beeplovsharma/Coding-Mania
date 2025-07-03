class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        //odd check
        for(int ax=0;ax<n;ax++){
            int orbl = ax-1;
            int orbr = ax+1;
            while(orbl>=0 && orbr<n && s[orbl]==s[orbr]){
                orbl--;
                orbr++;
            }
            int len = orbr-orbl-1;
            if(len>ans.size()) ans = s.substr(orbl+1,len);
        }

        //even check
        for(int ax=0;ax<n-1;ax++){
            int orbl = ax;
            int orbr = ax+1;
            while(orbl>=0 && orbr<n && s[orbl]==s[orbr]){
                orbl--;
                orbr++;
            }
            int len = orbr-orbl-1;
            if(len>ans.size()) ans = s.substr(orbl+1,len);
        }

        return ans;
    }
};