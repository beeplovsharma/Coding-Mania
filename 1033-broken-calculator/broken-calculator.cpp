class Solution {
public:
    int brokenCalc(int startValue, int target) {
        long long cnt = 0;
        while(target>=0){
            if(target==startValue) break;

            if(target&1 || target<startValue) target+=1;
            else target=target/2;

            cnt++;
        }
        return cnt;
    }
};