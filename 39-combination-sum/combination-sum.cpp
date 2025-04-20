class Solution {
public:
    void fun(vector<int>& nums,int ind,vector<int>&curr ,int target,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || ind==nums.size()) return;
        

        fun(nums,ind+1,curr,target,ans); // skip
        curr.push_back(nums[ind]);
        fun(nums,ind,curr,target-nums[ind],ans);
        curr.pop_back();

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>curr;
        fun(candidates,0,curr,target,ans);
        return ans;
    }
};