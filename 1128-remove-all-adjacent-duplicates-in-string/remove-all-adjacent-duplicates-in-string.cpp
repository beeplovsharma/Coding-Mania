class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto x:s){
            if(!st.empty()){
                char top = st.top();
                if(x==top) {
                    st.pop();
                    continue;
                }
            }
            st.push(x);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};