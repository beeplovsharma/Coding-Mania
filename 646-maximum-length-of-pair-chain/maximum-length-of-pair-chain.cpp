class Solution {
public:
    int fun(vector<vector<int>>& pairs, int ind, int prev, vector<vector<int>>& dp) {
        if (ind == pairs.size()) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int skip = fun(pairs, ind + 1, prev, dp);
        int take = 0;
        if (prev == -1 || pairs[prev][1] < pairs[ind][0]) {
            take = 1 + fun(pairs, ind + 1, ind, dp);
        }

        return dp[ind][prev + 1] = max(skip, take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return fun(pairs, 0, -1, dp);
    }

};