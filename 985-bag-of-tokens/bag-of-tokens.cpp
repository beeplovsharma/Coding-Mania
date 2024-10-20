class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i=0,j=n-1;
        int score = 0;
        int maxi = 0;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                power -= tokens[i];
                score++;
                i++;
                maxi = max(maxi,score);
            }
            else if(score>0){
                score--;
                maxi = max(maxi,score);
                power+=tokens[j];
                j--;
            }
            else{
                return maxi;
            }
        }
        return maxi;
    }
};