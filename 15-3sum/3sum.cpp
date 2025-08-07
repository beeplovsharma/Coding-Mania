class Solution {
public:
    // Pepcoding
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }else{
                    k--;
                }
            }
        }

        return vector<vector<int>>(begin(st),end(st));
    }
};