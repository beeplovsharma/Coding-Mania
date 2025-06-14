class Solution {
public:
    void fun(vector<int>& nums,vector<int>&asf,vector<bool>&vis,vector<vector<int>>&ans){
        if(asf.size()==nums.size()){
            ans.push_back(asf);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                asf.push_back(nums[i]);
                vis[i]=true;
                fun(nums,asf,vis,ans);
                asf.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>asf;
        vector<bool>vis(n,false);

        fun(nums,asf,vis,ans);

        return ans;
    }
};