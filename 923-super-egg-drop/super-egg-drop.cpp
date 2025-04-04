class Solution {
public:
    int fun(int k,int n,vector<vector<int>>&dp){
        if(k==0) return 0;
        if(k==1) return n;
        if(n==0) return 0;
        if(n==1) return 1;

        if(dp[k][n]!=-1) return dp[k][n];

        int lo = 1, hi = n;
        int minMoves = INT_MAX;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int eggBreak = fun(k-1,mid-1,dp);
            int notBreak = fun(k,n-mid,dp);
            int worstCase = 1 + max(eggBreak,notBreak);

            if(eggBreak<notBreak) lo=mid+1;
            else hi = mid-1;

            minMoves = min(minMoves,worstCase);
        }

        return dp[k][n] = minMoves;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return fun(k,n,dp);
    }
};