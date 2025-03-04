class Solution {
public:
    #define ll long long
    bool fun(int n,int p,ll sum){
        if(sum>n) return false;
        if(sum==n) return true;

        if(pow(3,p)>1e7) return false;
        bool take = fun(n,p+1,sum+pow(3,p));
        bool notTake = fun(n,p+1,sum);

        return (take || notTake);
    }
    bool checkPowersOfThree(int n) {
       return fun(n,0,0);
    }
};