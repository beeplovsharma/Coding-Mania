class Solution {
public:
    int N;
    int dp[100001];
    int fun(int ind, vector<int>& nums, int k){
        if(ind>=N) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = nums[ind] + fun(ind+k,nums,k);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        N = energy.size();
        memset(dp,-1,sizeof(dp));
        int ans = INT_MIN;
        for(int i=0;i<N;i++){
            ans = max(ans,fun(i,energy,k));
        }
        return ans;
    }
};