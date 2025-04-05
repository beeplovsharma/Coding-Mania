class Solution {
public:
    vector<vector<int>> fun(vector<int>& arr, int idx){
        if (idx == arr.size()) {
            return { {} };  // base case: empty subset
        }

        // faith: get subsets of the rest
        vector<vector<int>> smallAns = fun(arr, idx + 1);
        vector<vector<int>> result;

        for (auto subset : smallAns) {
            result.push_back(subset); // without current element
            subset.insert(subset.begin(), arr[idx]); // with current element
            result.push_back(subset);
        }

        return result;
    }
    int subsetXORSum(vector<int>& nums) {
        auto ans = fun(nums,0);
        int sum = 0;
        for(int i=1;i<ans.size();i++){
            int xorr = 0;
            for(int j=0;j<ans[i].size();j++){
                xorr = xorr ^ ans[i][j];
            }
            sum+=xorr;
        }
        return sum;
    }
};