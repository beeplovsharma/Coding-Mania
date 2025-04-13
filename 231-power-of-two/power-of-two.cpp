class Solution {
public:
    bool isPowerOfTwo(int n) {
        return ((n>0) && 1073741824%n==0); //2^31 = 1073741824
    }
};