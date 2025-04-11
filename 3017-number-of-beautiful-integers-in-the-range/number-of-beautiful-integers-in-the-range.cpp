typedef long long ll;

class Solution {
public:
    // index, tight, odd, even, remainder, validNum
    int dp[10][2][6][6][20][2];

    int f(int index, bool tight, int odd, int even, int rem, bool validNum, int &k, string &s) {
        // base case
        if (index == s.size()) 
            return (validNum && odd == even && rem == 0);

        // pruning
        if (odd > 5 || even > 5) return 0;

        // already calculated
        if (dp[index][tight][odd][even][rem][validNum] != -1)
            return dp[index][tight][odd][even][rem][validNum];

        int limit = tight ? s[index] - '0' : 9;
        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            int newTight = tight && (d == limit);
            if (validNum == false && d == 0) {
                ans += f(index + 1, newTight, odd, even, rem, false, k, s);
            } else if (d % 2 == 0) {
                ans += f(index + 1, newTight, odd, even + 1, (rem * 10 + d) % k, true, k, s);
            } else {
                ans += f(index + 1, newTight, odd + 1, even, (rem * 10 + d) % k, true, k, s);
            }
        }

        return dp[index][tight][odd][even][rem][validNum] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        string l = to_string(low - 1);
        memset(dp, -1, sizeof(dp));
        int countNum1 = f(0, true, 0, 0, 0, false, k, l);

        string h = to_string(high);
        memset(dp, -1, sizeof(dp));
        int countNum2 = f(0, true, 0, 0, 0, false, k, h);

        return countNum2 - countNum1;
    }
};
