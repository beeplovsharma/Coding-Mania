class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n = nums.size();
       set<vector<int>>st;
       int tar = 0;
       for(int i=0;i<n;i++){
        int ntar = tar-nums[i];
        int l = i+1;
        int r = n-1;

        while(l<r){
            if(nums[l]+nums[r]==ntar){
                st.insert({nums[i],nums[l],nums[r]});
                l++;
                r--;
            }else if(nums[l]+nums[r]<ntar){
                l++;
            }else{
                r--;
            }
        }
       }

       return vector<vector<int>>(st.begin(),st.end());
    }
};