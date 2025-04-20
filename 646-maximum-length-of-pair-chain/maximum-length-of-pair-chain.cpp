class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int skip = dp[ind + 1][prev+1];
                int take = 0;
                if (prev == -1 || pairs[prev][1] < pairs[ind][0]) {
                    take = 1 + dp[ind + 1][ind+1];
                }

                dp[ind][prev + 1] = max(skip, take);
            }
        }

        return dp[0][-1+1];
    }

};