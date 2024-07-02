class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
    
    for (char c : s) {
        if (!st.empty() && st.top().first == c) {
            st.top().second++;
        } else {
            st.push({c, 1});
        }
        
        if (st.top().second == k) {
            st.pop();
        }
    }
    
    string ans;
    while (!st.empty()) {
        ans.append(st.top().second, st.top().first);
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
    }
};