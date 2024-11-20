class Solution {
public:
    bool checkCapital(char c){
        return (c>='A' && c<='Z');
    }
    bool checkSmall(char c){
        return (c>='a' && c<='z');
    }
    bool detectCapitalUse(string word) {
        if(checkSmall(word[0])){
            for(auto c:word){
                if(checkCapital(c)) return false;
            }
            return true;
        }

        else{
            if(checkCapital(word[1])){
                for(int i=2;i<word.size();i++){
                    if(checkSmall(word[i])) return false;
                }
            }
            else{
                for(int i=2;i<word.size();i++){
                    if(checkCapital(word[i])) return false;
                }
            }
        }

        return true;
    }
};