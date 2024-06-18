class Solution {
    #define ll long long
public:
    bool judgeSquareSum(int c) {
        for(ll a=0;a*a<=c;a++){
            ll b = sqrt(c-a*a);
            if( a*a + b*b == c) return true;
        }
        return false;

        // int i=0,j = (long)sqrt(c);
        // while(i<=j){
        //     long test = i*i + j*j;
        //     if(test == c) return true;
        //     if(test<c) i++;
        //     if(test>c) j--;
        // }
        // return false;
    }
};