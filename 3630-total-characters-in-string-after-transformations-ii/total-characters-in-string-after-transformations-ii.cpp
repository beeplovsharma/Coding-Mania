class Solution {
public:
    const int M = 1e9+7;
    using Matrix = vector<vector<int>>;

    Matrix multiply(Matrix& A, Matrix& B) {
        Matrix res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < 26; ++j) {
                    res[i][j] = (res[i][j] + 1LL * A[i][k] * B[k][j]) % M;
                }
            }
        }
        return res;
    }

    Matrix matrixExpo(Matrix base, int power) {
        Matrix res(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) res[i][i] = 1;
        while (power) {
            if (power & 1) res = multiply(res, base);
            base = multiply(base, base);
            power >>= 1;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> hash(26);
        for (auto &ch : s) hash[ch - 'a']++;

        // Create transformation matrix
        Matrix T(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                T[i][(i + j) % 26] = (T[i][(i + j) % 26] + 1) % M;
            }
        }

        // Raise matrix to power t
        Matrix T_pow = matrixExpo(T, t);

        // Multiply hash vector with T_pow
        vector<int> result(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                result[j] = (result[j] + 1LL * hash[i] * T_pow[i][j]) % M;
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + result[i]) % M;
        }

        return ans;
    }
};
