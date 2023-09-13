class Solution {
public:
    void permutation(int ind,vector<int>&nums,vector<vector<int>>&ans){
        int n = nums.size();
        if(ind==n){
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);
            permutation(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        permutation(0,nums,ans);
        return ans;
    }
};