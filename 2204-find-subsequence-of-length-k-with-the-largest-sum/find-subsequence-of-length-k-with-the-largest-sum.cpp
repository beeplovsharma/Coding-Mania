class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        });

        vector<pair<int, int>> temp(v.begin(), v.begin() + k);

        sort(temp.begin(), temp.end(), cmp);

        vector<int> ans;
        for(int i = 0; i < temp.size(); i++) {
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};