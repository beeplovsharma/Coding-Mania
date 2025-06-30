class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int tar = 0;
        for(int i=0;i<n;i++){
            int newTar = tar - nums[i];

            int l = i+1;
            int r = n-1;

            while(l<r){
                if(nums[l]+nums[r]==newTar){
                    st.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }else if(nums[l]+nums[r]<newTar){
                    l++;
                }else{
                    r--;
                }
            } 
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};