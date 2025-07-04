class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n = nums.size();
       set<vector<int>>st;
       for(int i=0;i<n;i++){
        int l = i+1;
        int r = n-1;

        while(l<r){
            if(nums[i]+nums[l]+nums[r]==0){
                st.insert({nums[i],nums[l],nums[r]});
                l++;
                r--;
            }else if(nums[i]+nums[l]+nums[r]<0){
                l++;
            }else{
                r--;
            }
        }
       }

       return vector<vector<int>>(st.begin(),st.end());
    }
};