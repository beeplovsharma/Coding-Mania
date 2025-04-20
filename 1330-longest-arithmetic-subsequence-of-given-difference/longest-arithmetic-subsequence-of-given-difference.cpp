class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int las = 1;
        unordered_map<int,int>mp;
        for(auto &x:arr){
            las = max(las,mp[x] = 1 + mp[x-difference]);
        }
        return las;
    }
};