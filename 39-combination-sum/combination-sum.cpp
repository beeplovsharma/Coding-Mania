class Solution {
public:
    vector<vector<int>> fun(int idx, int target, vector<int>& candidates) {
        if (target == 0) return {{}};
        if (target < 0 || idx == candidates.size()) return {};

        vector<vector<int>> include = fun(idx, target - candidates[idx], candidates);
        vector<vector<int>> exclude = fun(idx + 1, target, candidates);

        vector<vector<int>> result;

        for (auto vec : include) {
            vec.insert(vec.begin(), candidates[idx]);
            result.push_back(vec);
        }

        for (auto vec : exclude) {
            result.push_back(vec);
        }

        return result;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return fun(0, target, candidates);
    }
};