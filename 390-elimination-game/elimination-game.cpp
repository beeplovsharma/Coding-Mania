class Solution {
public:
    int fun(int n,bool LR){
        if(n==1) return 1;

        if(LR){
            return 2 * fun(n/2,false);
        }else{
            if(n%2==0) return 2*fun(n/2,true)-1;
            else return 2 * fun(n/2,true);
        }
    }
    int lastRemaining(int n) {
        return fun(n,true);
    }
};