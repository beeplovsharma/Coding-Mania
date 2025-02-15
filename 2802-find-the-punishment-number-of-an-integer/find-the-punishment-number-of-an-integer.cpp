class Solution {
public:
    bool check(int sq,int tar,int sum){
        if(sq==0) return sum==tar;

        return check(sq/10,tar,sum+sq%10) ||
        check(sq/100,tar,sum+sq%100) ||
        check(sq/1000,tar,sum+sq%1000) ||
        check(sq/10000,tar,sum+sq%10000);
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