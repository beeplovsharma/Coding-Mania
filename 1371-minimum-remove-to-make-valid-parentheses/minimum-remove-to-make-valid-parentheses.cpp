class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        set<int>hash;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z') continue;

            if(s[i]=='(') st.push({'(',i});
            else{
                if(!st.empty() && st.top().first=='(') st.pop();
                else hash.insert(i);
            }
        }

        while(!st.empty()){
            auto tp = st.top();
            hash.insert(tp.second);
            st.pop();
        }

        string ans = "";
        for(int i=0;i<s.size();i++){
            if(hash.count(i)) continue;
            ans+=s[i];
        }

        return ans;
    }
};