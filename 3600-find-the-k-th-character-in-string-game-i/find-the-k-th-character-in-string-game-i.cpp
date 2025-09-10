class Solution {
public:
    char nextChar(char ch){
        if(ch>='a' && ch<'z') return char(ch+1);
        return 'a';
    }
    void fun(string &s, int k){
        if(s.size()>=k) return;

        string temp = "";
        for(auto c:s){
            temp += nextChar(c);
        }
        s+=temp;

        fun(s,k);
    }
    char kthCharacter(int k) {
        string s = "a";
        fun(s,k);
        cout<<s<<endl;
        return s[k-1];
    }
};