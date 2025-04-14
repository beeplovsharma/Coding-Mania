class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        int nn = n;
        while(nn){
            int rsb = nn & (-nn);
            nn = nn-rsb;
            cnt++;
        }
        return cnt;
    }
};