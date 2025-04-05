class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[n-1] = true;
        for(int ind=n-2;ind>=0;ind--){
            bool flag = false;
            for(int jump=1;jump<=nums[ind];jump++){
                if(ind+jump<n) flag = flag | dp[ind+jump];
            }

            dp[ind] = flag;
        }
        return dp[0];
    }
};