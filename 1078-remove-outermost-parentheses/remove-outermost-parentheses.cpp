class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans = "";
        int i=0,j=0;
        int n = s.size();
        while(j<n){
            if(s[j]=='(') st.push(s[j]);
            else st.pop();

            if(st.empty() && i+1<s.size() && j-i-1>=0){
                ans += s.substr(i+1,j-i-1);
                i=j+1;
            }
            j++;
        }
        return ans;
    }
};