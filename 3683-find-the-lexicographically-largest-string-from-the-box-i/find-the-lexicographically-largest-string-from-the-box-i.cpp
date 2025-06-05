class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int i=0,j=0;
        int n = word.size();

        while(j<n){
            if(word[i]<word[j]) i=j;
            else {
                if(word.substr(i)<word.substr(j)) i=j;
            }
            j++;
        }

        string larSuffix = word.substr(i);
        int len = larSuffix.size();

        if(len<=n-numFriends+1) return larSuffix;

        return larSuffix.substr(0,n-numFriends+1);
        
    }
};