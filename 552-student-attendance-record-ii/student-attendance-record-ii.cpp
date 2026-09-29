class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>>dp;
    int fun(int n,int A, int L){
        if(A > 1 || L > 2) return 0;
        if(n==0) return 1;

        if(dp[n][A][L]!=-1) return dp[n][A][L];
        
        int count = 0;

        count = (count + fun(n-1,A,0) % MOD) % MOD; // Present
        count = (count + fun(n-1,A+1,0) % MOD) % MOD; // Absent
        count = (count + fun(n-1,A,L+1) % MOD) % MOD; // Late

        return dp[n][A][L] = count % MOD;
    }
    int checkRecord(int n) {
        dp.resize(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(n,0,0);
    }
};