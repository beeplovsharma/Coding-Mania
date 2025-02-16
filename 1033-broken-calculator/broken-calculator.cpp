class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(target<=startValue) return (startValue-target);

        if(!(target&1)) return 1+brokenCalc(startValue,target/2);

        return 1+brokenCalc(startValue,target+1);
    }
};