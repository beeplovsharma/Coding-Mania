class Solution {
public:
    void PSS(vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans,int ind,int target){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(target < 0) break;
            ds.push_back(arr[i]);
            PSS(arr,ds,ans,i+1,target-arr[i]);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        PSS(candidates,ds,ans,0,target);
        return ans;
    }
};