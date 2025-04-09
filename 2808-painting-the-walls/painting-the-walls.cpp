class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));

        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int wallsLeft = 1; wallsLeft <= n; wallsLeft++) {
                int skip = dp[ind + 1][wallsLeft];

                int remaining = max(0, wallsLeft - 1 - time[ind]);
                int paint = cost[ind] + dp[ind + 1][remaining];

                dp[ind][wallsLeft] = min(skip, paint);
            }
        }

        return dp[0][n];
    }

};