class Solution {
public:
    int distributeCandies(int n, int limit) {
        int cnt = 0;
        
        for(int i=0;i<=min(n,limit);i++){
            for(int j=0;j<=min(n,limit);j++){
                int k = n-(i+j);
                if(k>limit) continue;

                if(k>=0) cnt++;
            }
        }
        return cnt;
    }
};