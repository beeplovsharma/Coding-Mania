class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(),m=t.size();
        vector<double>prev(m+1,0),cur(m+1,0);
        // vector<vector<double>>dp(n+1,vector<double>(m+1,0));

        prev[0] = 1;
        cur[0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                double one = 0;
                double two = 0;
                if(s[i-1]==t[j-1])
                    one = prev[j-1] + prev[j];
                else
                    two = prev[j];
                
                cur[j] = one+two;
            }
            prev = cur;
        }
        return (int)cur[m];
    }
};