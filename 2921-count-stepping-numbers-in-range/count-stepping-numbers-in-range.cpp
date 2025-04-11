class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;
    ll dp[101][2][10][2];

    ll fun(int ind, bool tight, int prev, bool validNum, string& s) {
        if (ind == s.size()) {
            return validNum;
        }

        if (dp[ind][tight][prev][validNum] != -1)
            return dp[ind][tight][prev][validNum];

        ll ans = 0;
        int limit = tight ? s[ind] - '0' : 9;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            if (!validNum && d == 0)
                ans = (ans + fun(ind + 1, newTight, prev, false, s)) % MOD;
            else if (!validNum && d > 0)
                ans = (ans + fun(ind + 1, newTight, d, true, s)) % MOD;
            else if (abs(d - prev) == 1)
                ans = (ans + fun(ind + 1, newTight, d, true, s)) % MOD;
        }

        return dp[ind][tight][prev][validNum] = ans;
    }

    int countSteppingNumbers(string low, string high) {
        memset(dp, -1, sizeof(dp));
        ll c1 = fun(0, true, 0, false, low);

        bool isStep = true;
        for (int i = 1; i < low.size(); i++) {
            if (abs(low[i] - low[i - 1]) != 1) {
                isStep = false;
                break;
            }
        }
        if (isStep) c1--;

        memset(dp, -1, sizeof(dp));
        ll c2 = fun(0, true, 0, false, high);

        return ((c2 - c1 + MOD) % MOD);
    }
};
