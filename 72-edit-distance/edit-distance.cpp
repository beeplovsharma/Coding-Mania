class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int>prev(m+1,0),cur(m+1,0);
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int j=0;j<=m;j++) prev[j] = j;

        for(int i=1;i<=n;i++){
            cur[0] = i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    cur[j] = prev[j-1];
                }
                else{
                    int replace = 1+prev[j-1];
                    int del = 1+prev[j];
                    int ins = 1+cur[j-1];
                    cur[j] = min(replace,min(del,ins));
                }
            }
            prev = cur;
        }

        return prev[m];
    }
};