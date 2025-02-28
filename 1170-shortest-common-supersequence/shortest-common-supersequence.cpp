class Solution {
public:
unordered_map<string, string> dp;

string SCS(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    
    // Step 1: Build the DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill DP table with SCS lengths
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Match, take diagonal
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]); // Take min from left or top
        }
    }

    // Step 2: Reconstruct the SCS string from dp table
    int i = m, j = n;
    string result;
    
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {  // Characters match, take diagonally
            result += s1[i - 1];
            i--, j--;
        } 
        else if (dp[i - 1][j] < dp[i][j - 1]) {  // Move up
            result += s1[i - 1];
            i--;
        } 
        else {  // Move left
            result += s2[j - 1];
            j--;
        }
    }

    // Add remaining characters from either string
    while (i > 0) result += s1[--i];
    while (j > 0) result += s2[--j];

    // Reverse to get the final SCS
    reverse(result.begin(), result.end());
    return result;
}

    string shortestCommonSupersequence(string str1, string str2) {
        return SCS(str1,str2);
    }
};