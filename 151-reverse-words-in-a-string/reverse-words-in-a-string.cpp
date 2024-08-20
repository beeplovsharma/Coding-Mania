class Solution {
public:
// Tokenizer Method
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "";
        string result = "";
        while(ss >> token){
            result = token + " " + result;
        }
        int len = result.size();
        return result.substr(0,len-1);
    }
};