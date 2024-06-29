class Solution {
public:
    int brute(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i==0 && nums[i]!=nums[i+1]) return nums[i];
            else if(i==n-1 && nums[i]!=nums[i-1]) return nums[i];
            else{
                if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1]) return nums[i];
            }
        }
        return -1;
    }

    int better(vector<int>&nums){
        int n = nums.size();
        int ans = nums[0];
        for(int i=1;i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }

    int singleNonDuplicate(vector<int>& nums) {
        return better(nums);
    }
};