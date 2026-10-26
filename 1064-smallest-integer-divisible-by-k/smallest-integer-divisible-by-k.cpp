class Solution {
public:
    int smallestRepunitDivByK(int k) {
       int cnt = 0;
       int i = k;
       int rem = 0;
       while(i--){
        rem = rem * 10 + 1;
        rem = rem % k;
        cnt++;
        if(rem==0) return cnt;
       }

       return -1;
    }
};