class Solution {
public:
    vector<int> nums;

    vector<int> getSubsetEndingAt(int i, vector<vector<int>>&dp) {
        if(!dp[i].empty()) return dp[i];

        vector<int> bestSubset = {nums[i]};

        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0) {
                vector<int> prevSubset = getSubsetEndingAt(j,dp);
                if (prevSubset.size() + 1 > bestSubset.size()) {
                    bestSubset = prevSubset;
                    bestSubset.push_back(nums[i]);
                }
            }
        }

        return dp[i] = bestSubset;
    }

    vector<int> largestDivisibleSubset(vector<int>& input) {
        nums = input;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> answer;
        vector<vector<int>>dp(n);

        for (int i = 0; i < n; i++) {
            vector<int> candidate = getSubsetEndingAt(i,dp);
            if (candidate.size() > answer.size()) {
                answer = candidate;
            }
        }

        return answer;
    }
};