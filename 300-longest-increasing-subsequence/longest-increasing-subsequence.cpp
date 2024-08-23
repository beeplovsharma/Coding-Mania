class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        int maxi = 0;
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(arr[prev] < arr[ind]){
                    dp[ind] = max(dp[ind],1+dp[prev]);
                }
            }
            maxi = max(maxi,dp[ind]);
        }
        return maxi;
    }
};