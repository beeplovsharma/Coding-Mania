class Solution {
public:
    typedef long long ll;
    int N;
    ll dp[100001];
    ll fun(vector<vector<int>>& nums,int ind){
        if(ind>=N) return 0;

        if(dp[ind]!=-1) return dp[ind];

        ll skip = fun(nums,ind+1);
        ll solve = (ll)nums[ind][0] + fun(nums,ind+nums[ind][1]+1);

        return dp[ind] = max(skip,solve);
    }
    long long mostPoints(vector<vector<int>>& ques) {
        N = ques.size();
        memset(dp,-1,sizeof(dp));
        return fun(ques,0);
    }
};