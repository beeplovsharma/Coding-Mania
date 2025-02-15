class Solution {
public:
    bool check(int sq,int tar,int sum){
        if(sq==0) return sum==tar;

        int p = 1;
        for(int i=1;i<=4;i++){
            p = p * 10;
            int rem = sq % p;
            int newSq = sq / p;
            if(check(newSq,tar,sum+rem)) return true;
        }

        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int sq = i*i;
            if(check(sq,i,0)){
                ans += sq;
            }
        }
        return ans;
    }
};