class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans1;

        int flag = 0;
        int n = words.size();
        for(int i=0;i<n;i++){
            if(flag != groups[i]){
                ans1.push_back(words[i]);
                flag = !flag;
            }
        }

        flag = 1;
        vector<string>ans2;
        for(int i=0;i<n;i++){
            if(flag != groups[i]){
                ans2.push_back(words[i]);
                flag = !flag;
            }
        }

        return ans1.size() > ans2.size() ? ans1 : ans2;
    }
};