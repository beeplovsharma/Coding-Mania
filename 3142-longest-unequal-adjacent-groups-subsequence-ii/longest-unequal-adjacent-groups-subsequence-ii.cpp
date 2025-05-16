class Solution {
public:
    bool checkHammingDist(string &a, string &b) {
        int ham = 0;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) ham++;
            if (ham > 1) return false;
        }
        return ham == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);

        int longestSub = 1;
        int longestSubInd = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && 
                    words[i].size() == words[j].size() && 
                    checkHammingDist(words[i], words[j])) {
                    
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > longestSub) {
                longestSub = dp[i];
                longestSubInd = i;
            }
        }

        vector<string> res;
        while (longestSubInd != -1) {
            res.push_back(words[longestSubInd]);
            longestSubInd = parent[longestSubInd];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
