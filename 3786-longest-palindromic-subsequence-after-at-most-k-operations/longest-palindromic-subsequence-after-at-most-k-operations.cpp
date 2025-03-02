class Solution {
public:
int fun(string &s, int i, int j, int k, vector<vector<vector<int>>>& dp) {
    if (i > j) return 0;
    if (i == j) return 1;

    if (dp[i][j][k] != -1) return dp[i][j][k];

    // Case 1: Exclude s[i] or s[j]
    int maxLen = max(fun(s, i + 1, j, k, dp), fun(s, i, j - 1, k, dp));

    // Case 2: Try to include s[i] and s[j] in the palindrome
    int opsReq = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j])); // Cyclic difference
    
    if (opsReq <= k) {
        maxLen = max(maxLen, 2 + fun(s, i + 1, j - 1, k - opsReq, dp));
    }

    return dp[i][j][k] = maxLen;
}

int longestPalindromicSubsequence(string s, int k) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
    return fun(s, 0, n - 1, k, dp);
}
};