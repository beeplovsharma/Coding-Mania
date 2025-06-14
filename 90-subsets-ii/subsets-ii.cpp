class Solution {
public:
    void fun(vector<int>& nums,int i,vector<int>asf,set<vector<int>>&ans) {
        if(i==nums.size()){
            ans.insert(asf);
            return;
        }
        
        asf.push_back(nums[i]);
        fun(nums,i+1,asf,ans);
        asf.pop_back();

        fun(nums,i+1,asf,ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>ans;
        vector<int>asf;
        fun(nums,0,asf,ans);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};