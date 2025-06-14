class Solution {
public:
    void fun(vector<int>& nums,int i,vector<int>asf,vector<vector<int>>&ans) {
        if(i==nums.size()){
            ans.push_back(asf);
            return;
        }
        
        asf.push_back(nums[i]);
        fun(nums,i+1,asf,ans);
        asf.pop_back();

        fun(nums,i+1,asf,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>asf;
        fun(nums,0,asf,ans);
        return ans;
    }
};