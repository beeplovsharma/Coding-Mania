class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        map<char,vector<int>>mp;

        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                for(auto &x:mp){
                    if(x.second.size()>0){
                        int idx = x.second.back();
                        s[idx]='*';
                        x.second.pop_back();
                        break;
                    }
                }
            }else{
                mp[s[i]].push_back(i);
            }
        }

        string ans = "";
        for(auto x:s){
            if(x!='*') ans+=x;
        }

        return ans;
    }
};