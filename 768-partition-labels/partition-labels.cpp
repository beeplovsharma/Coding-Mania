class Solution {
public:
    bool check(unordered_map<char, int>& hash, unordered_map<char, int>& mp) {
        for (auto x : mp) {
            if (x.second != hash[x.first]) return false;
        }
        return true;
    }

    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hash;

        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]++;
        }

        vector<int> ans;
        unordered_map<char, int> mp;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (j < s.size()) {
                mp[s[j]]++;
                if (check(hash, mp)) break; 
                j++;
            }

            ans.push_back(j - i + 1);
            mp.clear();
            i = j + 1;
        }

        return ans;
    }
};
