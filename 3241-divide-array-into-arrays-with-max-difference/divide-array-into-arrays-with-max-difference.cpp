class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        int i=0;
        while(i<n){
            if((nums[i+2]-nums[i])<=k){
                vector<int>temp;
                for(int j=i;j<=i+2;j++) temp.push_back(nums[j]);
                ans.push_back(temp); 
            }else{
                return {};
            }
            i+=3;
        }

        return ans;
    }
};