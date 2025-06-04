class Solution {
public:
    bool isValid(string &word,unordered_map<char,int>letterHash){
        for(auto &x:word){
            letterHash[x]--;
            if(letterHash[x]<0) return false;
        }
        return true;
    }

    void calcMax(vector<string>&asf,unordered_map<string,int>scoreHash,int &ans){
        int sc = 0;
        for(auto &word:asf){
            sc += scoreHash[word];
        }
        ans = max(ans,sc);
    }

    void solve(vector<string>& words,int ind,unordered_map<char,int>&letterHash,unordered_map<string,int>&scoreHash,int &ans,vector<string>&asf){
        if(ind==words.size()){
            calcMax(asf,scoreHash,ans);
            return;
        }

        solve(words,ind+1,letterHash,scoreHash,ans,asf); //notPick

        if(!isValid(words[ind],letterHash)) return;

        for(auto &x:words[ind]) letterHash[x]--;
        asf.push_back(words[ind]);
        solve(words,ind+1,letterHash,scoreHash,ans,asf); //pick
        for(auto &x:words[ind]) letterHash[x]++;
        asf.pop_back();
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>letterHash;
        for(auto &x:letters) letterHash[x]++;
        unordered_map<string,int>scoreHash;
        for(auto &word:words){
            int sc = 0;
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                sc+=score[ch-'a'];
            }
            scoreHash[word]=sc;
        }
        
        int ans = 0;
        vector<string>asf;

        solve(words,0,letterHash,scoreHash,ans,asf);

        return ans;
    }
};