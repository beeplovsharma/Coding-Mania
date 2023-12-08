class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        string str = "";
        if(str1+str2 == str2+str1){
            int g = gcd(m,n);
            str = str1.substr(0,g);
            return str;
        }

        if(str1+str2 != str2+str1) return str;

        return str;
    }
};