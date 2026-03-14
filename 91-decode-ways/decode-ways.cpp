class Solution {
public:
    int fun(string s,int ind,vector<int>&dp){
        if(ind<0) return 1;
        if(dp[ind]!=-1) return dp[ind];
        
        int first = 0;
        if(s[ind]!='0'){
            first = fun(s,ind-1,dp);
        }

        int second = 0;
        if(ind>0){
            int num = stoi(s.substr(ind-1,2));
            if(num>=10 && num<=26){
                second = fun(s,ind-2,dp);
            }
        }

        return dp[ind] = first + second;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return fun(s,n-1,dp);
    }
};