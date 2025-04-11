class Solution {
public:
    int dp[11][2][6][6][2][20][21];
    int fun(string &s, int ind, bool tight, int odd, int even, bool leadZero, int rem, int &k) {
        if (ind == s.size()) {
            return (!leadZero && odd == even && rem == 0);
        }
        if ((odd > 5) || (even > 5)) return 0;

        if(dp[ind][tight][odd][even][leadZero][rem][k]!=-1) return dp[ind][tight][odd][even][leadZero][rem][k];

        int limit = tight ? s[ind] - '0' : 9;
        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == s[ind] - '0');
            bool newLeadZero = leadZero && (d == 0);
            int newOdd = odd + (d % 2 != 0 ? 1 : 0);
            int newEven = even + (d % 2 == 0 ? 1 : 0);
            if (newLeadZero) newOdd = newEven = 0;
            int remainder = (rem * 10 + d) % k;

            ans += fun(s, ind + 1, newTight, newOdd, newEven, newLeadZero, remainder, k);
        }

        return dp[ind][tight][odd][even][leadZero][rem][k] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string s1 = to_string(high);
        memset(dp,-1,sizeof(dp));
        int c1 = fun(s1, 0, true, 0, 0, true, 0, k);

        string s2 = to_string(low - 1);
        memset(dp,-1,sizeof(dp));
        int c2 = fun(s2, 0, true, 0, 0, true, 0, k);

        return c1 - c2;
    }
};