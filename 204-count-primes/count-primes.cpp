class Solution {
public:
    void checkPrime(vector<bool>&sieve){
        int n = sieve.size();
        for(int i=2;i*i<n;i++){
            if(sieve[i]){
                for(int j=i*i;j<n;j+=i){
                    sieve[j] = false;
                }
            }
        }
    }
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool>sieve(n,true);
        sieve[0] = sieve[1] = false;
        checkPrime(sieve);
        int cnt = 0;
        for(int i=2;i<n;i++){
            if(sieve[i]) cnt++;
        }
        return cnt;
    }
};