class Solution {
public:
    //Pepcoding
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }else if(sum<target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }

        return vector<vector<int>>(begin(st),end(st));
    }
};