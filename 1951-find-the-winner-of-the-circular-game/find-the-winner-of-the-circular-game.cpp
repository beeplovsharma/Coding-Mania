class Solution {
public:
    int fun(int n,int k){
        if(n==1) return 0;
        
        int faith = fun(n-1,k);
        int x = (faith+k)%n;

        return x;
    }
    int findTheWinner(int n, int k) {
        return fun(n,k)+1;
    }
};