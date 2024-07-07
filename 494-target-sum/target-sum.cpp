class Solution {
public:
    int solve(vector<int>& nums, int ind,int cur ,int target){
        if(ind<0) return (target==cur);
        if(ind<0) return 0;

        int add = solve(nums,ind-1,cur+nums[ind],target);
        int sub = solve(nums,ind-1,cur-nums[ind],target);

        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int cur = 0;
        return solve(nums,n-1,cur,target);
    }
};