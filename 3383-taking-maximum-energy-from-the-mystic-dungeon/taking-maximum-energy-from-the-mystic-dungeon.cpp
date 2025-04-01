class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int>dp(n,0);
        int maxi = INT_MIN;
        
        for(int ind=n-1;ind>=0;ind--){
            if (ind + k < n)
                dp[ind] = energy[ind] + dp[ind + k];
            else
                dp[ind] = energy[ind];
        }

        for(int i=0;i<n;i++){
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};