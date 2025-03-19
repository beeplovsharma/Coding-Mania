class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0 || n==1) return n;

        int cnt = 0;
        for(long long i=1;i<=n;i++){
            long long sq = sqrt(i);
            if(sq*1LL*sq==i) cnt++;
        }
        return cnt;
    }
};