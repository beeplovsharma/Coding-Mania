class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;

        int noOfRounds = k/n;
        int rem = k%n;

        if(noOfRounds%2==0){
            // Even Rounds
            return rem;
        }
        else{
            // Odd Rounds
            return (n-rem);
        }
    
    }
};