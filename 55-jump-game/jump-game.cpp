class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0,maxi = 0;
        int n = nums.size();

        while(maxi<n && i<n){
            if(i>maxi) break;

            maxi = max(maxi,i+nums[i]);
            i++;
        }
        if(maxi>=n-1) return true;

        return false;
    }
};