class Solution {
public:
    int dp[100001];
    const int M = 1e9+7;
    int fun(int len,int low, int high, int zero, int one){
        if(len>high) return 0;
        if(dp[len]!=-1) return dp[len];

        int curr = (len>=low) ? 1 : 0;
        int first = fun(len+zero,low,high,zero,one)%M;
        int second = fun(len+one,low,high,zero,one)%M;

        return dp[len] = (curr+first+second)%M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return fun(0,low,high,zero,one);
    }
};