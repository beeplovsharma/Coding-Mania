class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
        int n = word.size();
        int i = 0;
        for(int j=0;j<n;j++){
            if(word.substr(i)<word.substr(j)) i=j;
        }

        return word.substr(i,min(n-i+1,n-numFriends+1));
    }
};