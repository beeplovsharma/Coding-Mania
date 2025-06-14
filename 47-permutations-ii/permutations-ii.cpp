class Solution {
public:
    void fun(vector<int>& nums,vector<int>&asf,vector<bool>&vis,set<vector<int>>&ans){
        if(asf.size()==nums.size()){
            ans.insert(asf);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>>ans;
        vector<int>asf;
        vector<bool>vis(n,false);

        fun(nums,asf,vis,ans);

        return vector<vector<int>>(ans.begin(),ans.end());
    }
};