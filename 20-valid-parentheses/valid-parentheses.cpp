class Solution {
public:
    bool isValid(string s) {
        // Method - 2
        stack<char>st;
        for(auto ch : s){
            if(ch == '{'){
                st.push('}');
            }
            else if(ch == '('){
                st.push(')');
            }
            else if(ch == '['){
                st.push(']');
            }
            else if(st.empty() || st.top() !=ch){
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.empty();

        // Method - 1
        // stack<char>st;
        // for(int i=0;i<s.size();i++){
        //     if(st.empty() || s[i] == '(' || s[i]=='{' || s[i]=='['){
        //         st.push(s[i]);
        //         continue;
        //     }
        //     if(s[i] == ')'){
        //         if(st.top() == '(') st.pop();
        //         else return false;
        //     }
        //     else if(s[i] == '}'){
        //         if(st.top() == '{') st.pop();
        //         else return false;
        //     }
        //     else if(s[i] == ']'){
        //         if(st.top() == '[') st.pop();
        //         else return false;
        //     }
        // }
        // return st.empty();
    }
};