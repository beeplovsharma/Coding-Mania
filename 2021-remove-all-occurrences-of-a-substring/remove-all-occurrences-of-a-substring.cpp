class Solution {
public:
    bool findpart(stack<char>&st,string part){
        stack<char>temp = st;
        int n = part.size();
        for(int i=n-1;i>=0;i--){
            if(!temp.empty() && temp.top()!=part[i]) return false;
            temp.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();

        stack<char>st;
        for(int i=0;i<n;i++){
            st.push(s[i]);

            if(st.size()>=m && findpart(st,part)){
                for(int j=0;j<m;j++) st.pop();
            }
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};