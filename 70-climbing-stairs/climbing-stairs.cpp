class Solution {
public:
    int fun(int ind,vector<int>&dp){
        if(ind==0) return 1;
        if(ind==1) return 2;
        if(dp[ind]!=-1) return dp[ind];
        int f = 0,s=0;
        if(ind>=1) f = fun(ind-1,dp);
        if(ind>=2) s = fun(ind-2,dp);
        
        return dp[ind] = f+s;
    }
    int climbStairs(int n) {
        // vector<int>dp(n,0);

        if(n==1) return 1;

        int prev=1,cur=2;
        // dp[0] = 1;
        // dp[1] = 2;
        for(int ind=2;ind<n;ind++){
            int f = 0,s=0;
            if(ind>=1) f = cur;
            if(ind>=2) s = prev;
            
            prev = cur;
            cur = f+s;
        }
        return cur;
    }
};