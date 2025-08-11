class Solution {
public:
    bool check(vector<string>& wordDict,string &tar){
        for(auto &x:wordDict){
            if(tar==x) return true;
        }
        return false;
    }
    void fun(string s, string asf,vector<string>&ans ,vector<string>& wordDict){
        if(s.size()==0){
            asf.pop_back();
            ans.push_back(asf);
            return;
        }

        for(int i=0;i<s.size();i++){
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);
            if(check(wordDict,left)) fun(right,asf+left+" ",ans,wordDict);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        string asf = "";
        fun(s,asf,ans,wordDict);
        return ans;
    }
};