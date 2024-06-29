class Solution {
#define ll long long
public:
    int mySqrt(int x) {
        int ans = 0;
        for(ll i=1;i*i<=x;i++){
            if(i <= x/i){
                ans = i;
            }
        }
        return ans;
    }
};