class Solution {
public:
    int solve(vector<string>& words,int ind, unordered_map<char,int>freq,vector<int>& score){
        if(ind==words.size()) return 0;

        int notTake = solve(words,ind+1,freq,score);

        int sc = 0;
        string word = words[ind];
        bool flag = true;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            freq[ch]--;
            if(freq[ch]<0) flag = false;
            sc+=score[ch-'a'];
        }
        int take = 0;
        if(flag){
            take = sc + solve(words,ind+1,freq,score);
        }
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            freq[ch]++;
        }

        return max(take,notTake);


    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>freq;
        for(auto &x:letters) freq[x]++;
        return solve(words,0,freq,score); 
    }
};