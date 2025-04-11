class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low;i<=high;i++){
            if(i<100 && i%11==0){
                cnt++;
            }else if(i>1000){
                int fi = (i/1000);
                int se = (i/100)%10;
                int th = (i/10)%10;
                int fo = i%10;

                if(fi+se == th+fo) cnt++;
            }
        }
        return cnt;
    }
};