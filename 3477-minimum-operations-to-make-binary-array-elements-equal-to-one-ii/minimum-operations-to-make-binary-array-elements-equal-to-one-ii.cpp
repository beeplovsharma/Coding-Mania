class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int flips = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0 && flips==0){
                flips++;
            }

            if(flips%2==nums[i]) flips++;
        }
        return flips;
    }
};