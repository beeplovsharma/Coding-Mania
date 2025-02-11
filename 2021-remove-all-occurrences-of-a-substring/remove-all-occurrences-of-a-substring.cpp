class Solution {
public:
    bool findPart(stack<char>& st, const string& pp) {
        stack<char> temp = st;
        for (char c : pp) {
            if (temp.empty() || c != temp.top()) return false;
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        string pp = part;
        reverse(pp.begin(),pp.end());

        int n = s.size();
        int m = part.size();
        stack<char>st;
        int i=0;
        while(i<n){
            if(st.size()>=part.size() && findPart(st,pp)){
                for(int j=0;j<m;j++){
                 if(!st.empty()) st.pop();   
                }
            }
            st.push(s[i++]);
        }
        
        if(st.size()>=part.size() && findPart(st,pp)){
                for(int j=0;j<m;j++){
                 if(!st.empty()) st.pop();   
                }
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