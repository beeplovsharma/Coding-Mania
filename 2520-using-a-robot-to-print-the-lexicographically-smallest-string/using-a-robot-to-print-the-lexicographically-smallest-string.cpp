class Solution {
public:
    bool isNextSmall(char ch, vector<int>&hash){
        for(int i = 0; i < (ch - 'a'); i++){
            if(hash[i] > 0) return true;
        }
        return false;
    }

    string robotWithString(string s) {
        int n = s.size();
        vector<int> hash(26, 0);
        for(auto &c : s) hash[c - 'a']++;

        string helper = "", ans = "";
        for(int i = 0; i < n; i++){
            helper.push_back(s[i]);
            hash[s[i] - 'a']--;

            while(!helper.empty() && !isNextSmall(helper.back(), hash)){
                ans += helper.back();
                helper.pop_back();
            }
        }
        return ans;
    }
};
