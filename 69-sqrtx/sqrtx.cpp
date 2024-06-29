class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) return -1; // Handle negative input
    if (x == 0) return 0; // Handle zero input
    int low = 1;
    int high = x;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid potential overflow
        if (mid == x / mid) return mid; // Avoid potential overflow
        else if (mid < x / mid) low = mid + 1;
        else high = mid - 1;
    }
    return high;
    }
};