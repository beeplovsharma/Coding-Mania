#include<bits/stdc++.h>
const int mod = 1e9 + 7;
class Solution {
#define ll long long

public:
long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;
        long long even_choices = power(5, even_positions);
        long long odd_choices = power(4, odd_positions);
        return (even_choices * odd_choices) % mod;
    }
};