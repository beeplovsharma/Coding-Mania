class Solution {
public:
    void permutation(vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,int freq[]){
        int n = nums.size();
        if(nums.size()==ds.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<n;i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                permutation(nums,ds,ans,freq);

                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for(int i=0;i<n;i++) freq[i] = 0;
        vector<vector<int>> ans;
        permutation(nums,ds,ans,freq);
        return ans;
    }
};