class Solution {
    const int MOD = 1337;
    
    int modPow(int a, int k) {
        a %= MOD;
        int result = 1;
        for (int i = 0; i < k; ++i) {
            result = (result * a) % MOD;
        }
        return result;
    }
    
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        
        int lastDigit = b.back();
        b.pop_back();
        
        int part1 = modPow(superPow(a, b), 10); // a^[...b[:-1]]^10 % 1337
        int part2 = modPow(a, lastDigit);       // a^b[-1] % 1337
        
        return (part1 * part2) % MOD;
    }
};
