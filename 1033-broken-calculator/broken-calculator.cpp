class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(target<=startValue) return (startValue-target);

        int div = INT_MAX;
        if(!(target&1))
            return div = 1 +brokenCalc(startValue,target/2);
        
        int add = 1 + brokenCalc(startValue,target+1);

        return min(div,add);
    }
};