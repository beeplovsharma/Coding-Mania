class Solution {
public:
    string removeOuterParentheses(string str) {
        string ans = "";
        string temp = "";
        stack<char> st;
        
        for(int i=0;i<str.size();i++){

            if(str[i]==')'){
                st.pop();

                if(!st.empty())
                    temp.push_back(')');
                
                else{
                    ans+=temp;
                    temp="";
                }
            }

            else{
                if(!st.empty() && str[i]=='('){
                st.push('(');
                temp.push_back('(');
            }

            else{
                st.push('(');
            }
            }

            
        }
        return ans;
    }
};