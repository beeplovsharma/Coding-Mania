class Solution {
public:
    string fun(string s){
        string ans = "";
        int n = s.size();
        int i=0;
        int idx = 0;
        while(i<n){
            char cur_ch = s[i];
            int cnt = 0;
            while(i<n && s[i]==cur_ch){
                i++;
                cnt++;
            }
            ans+=to_string(cnt);
            ans+=s[idx];
            idx++;
            idx = i;
        }
        return ans;
    }
    string rec(int n) {
        if(n==1) return "1";
        
        string s = rec(n-1);
        return fun(s);
        
    }
    
    string countAndSay(int n) {
        string ans = rec(n);
        // reverse(ans.begin(),ans.end());
        return ans;
        
    }
};