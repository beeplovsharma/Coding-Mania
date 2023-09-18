class Solution {
public:
    string reverseWords(string str) {
    vector<string> words;
    string word = "";
    str.push_back(' ');
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            if(word.size()>0)
                words.push_back(word);
            word = "";
        }
        else{
            word.push_back(str[i]);
        }
    }
    reverse(words.begin(),words.end());
    string ans = "";
    for(auto x:words){
        ans += x;
        ans += " ";
    }
    ans.pop_back();
    return ans;
    }
};