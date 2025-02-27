class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
    unordered_map<int, int> index;
    vector<vector<int>> dp(n, vector<int>(n, 2)); // Base case: length of Fibonacci sequence is at least 2
    int maxLen = 0;

    // Store indices for quick lookup
    for (int i = 0; i < n; i++)
        index[arr[i]] = i;

    // Iterate over all pairs (i, j) where i < j
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            int x = arr[j] - arr[i]; // The number we expect to form a Fibonacci sequence
            if (index.count(x) && index[x] < i) {
                int k = index[x]; // Get the index of `x`
                dp[i][j] = dp[k][i] + 1; // Update DP state
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }

    return (maxLen >= 3) ? maxLen : 0;
    }
};