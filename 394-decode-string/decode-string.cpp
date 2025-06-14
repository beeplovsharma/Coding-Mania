class Solution {
public:
    string fun(string &s, int &i){
        if(i==s.size()) return "";

        string ans = "";

        while(i<s.size() && s[i]!=']'){
            if(isdigit(s[i])){
                int num = 0;

                while(i<s.size() && isdigit(s[i])){
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i++; //skip [
                
                string inner = fun(s,i);

                i++; //skip ]

                while(num--){
                    ans += inner;
                }
            }else{
                ans+=s[i];
                i++;
            }
        }

        return ans;
    }
    string decodeString(string s) {
        int i=0;
        return fun(s,i);
    }
};