class Solution {
public:
    bool checkPalindrome(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=j) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]) return dp[i][j] = checkPalindrome(s,i+1,j-1,dp);
        
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = INT_MIN;
        int sp=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(checkPalindrome(s,i,j,dp)){
                    int len = (j-i+1);
                    if(len > maxLen){
                        maxLen = len;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp,maxLen);
    }
};