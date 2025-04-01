class Solution {
public:
    int fun(vector<int>& energy, int k, int ind, vector<int>&dp){
        int n = energy.size();
        if (ind >= n) return 0;

        if(dp[ind]!=-1) return dp[ind];

        return dp[ind] = energy[ind] + fun(energy, k, ind + k,dp);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>dp(n+1,-1);
        int maxi = INT_MIN;
        for(int i=0;i<energy.size();i++){
            maxi = max(maxi,fun(energy,k,i,dp));
        }
        return maxi;
    }
};