class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>3){
            int rem = n%3;
            if(rem==2) return false;
            n=n/3;
        }

        if(n%3<2) return true;
        return false;
    }
};