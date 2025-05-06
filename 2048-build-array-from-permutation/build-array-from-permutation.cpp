class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<i){
                nums[i] = nums[i] + (nums[nums[i]]%n)*n;
            }else{
                nums[i] = nums[i] + (nums[nums[i]]*n);
            }

            cout<<nums[i]<<" ";
        }

        for(int i=0;i<n;i++) nums[i] = nums[i]/n;
        return nums;
    }
};