class Solution {
public:
    typedef long long ll;
    ll kp = 0;
    unordered_set<ll>done;
    vector<ll>fact;

    void precomputeFactorial(int &n){
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=10;i++){
            fact[i] = fact[i-1]*i;
        }
    }

    ll countAllPermutations(vector<ll>&freq,int n){
        ll count = fact[n];
        for(int i=0;i<=9;i++){
            count/=fact[freq[i]];
        }
        return count;
    }

    ll allArrangements(string number,int &n){
        sort(number.begin(),number.end());
        if(done.count(stoll(number))) return 0;

        done.insert(stoll(number));

        vector<ll>freq(10);
        for(char &c:number)
            freq[c-'0']++;
        
        ll totPermut = countAllPermutations(freq,n);
        ll invalidPermut = 0;
        if(freq[0]>0){
            freq[0]--;
            invalidPermut = countAllPermutations(freq,n-1);
        }
        return totPermut-invalidPermut;
    }

    bool isKPalindrome(string &number,int &n,int &k){
        return (stoll(number)%k==0);
    }

    void generatePalindrome(string number,int ind,int &n,int &k){
        if(ind>=(n+1)/2){
            if(isKPalindrome(number,n,k)){
                kp += allArrangements(number,n);
            }
            return;
        }

        for(int i=0;i<=9;i++){
            if(ind==0 && i==0) continue;
            number[ind] = i+'0';
            number[n-ind-1] = i+'0';
            generatePalindrome(number,ind+1,n,k);
        }
    }
    long long countGoodIntegers(int n, int k) {
        fact = vector<ll>(11);
        precomputeFactorial(n);
        string number(n,' ');
        generatePalindrome(number,0,n,k);
        return kp;
    }
};