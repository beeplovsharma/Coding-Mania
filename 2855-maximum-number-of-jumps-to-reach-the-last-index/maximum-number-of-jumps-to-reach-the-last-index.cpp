class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[n-1]=0;
        
        for(int ind=n-2;ind>=0;ind--){
            int maxJumps = -1e9;
            for(int jump=ind+1;jump<nums.size();jump++){
                int canJump = -1e9;
                if(abs(nums[jump]-nums[ind])<=target) canJump = 1+dp[jump];
                maxJumps = max(maxJumps,canJump); 
            }
            dp[ind] = maxJumps;
        }

        int ans = dp[0];
        return ans<=-1e8 ? -1 : ans;
    }
};