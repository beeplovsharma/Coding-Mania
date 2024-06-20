class Solution {
public:
    void solve(vector<int>& nums, int ind ,int target,vector<int>&ds,vector<vector<int>>&ans){
        if(ind==nums.size()){
            if(target==0) ans.push_back(ds);
            return;
        }

        if(target>=nums[ind]){
            ds.push_back(nums[ind]);
            solve(nums,ind,target-nums[ind],ds,ans);
            ds.pop_back();
        }
        solve(nums,ind+1,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(candidates,0,target,ds,ans);
        return ans;
    }
};