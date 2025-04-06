class Solution {
public:
    int getSum(vector<int>& nums){
        int sum = 0;
        for(auto &x:nums){
            sum += x;
        }
        return sum;
    }
    bool canPartition(vector<int>& nums) {
        int totSum = getSum(nums);
        if(totSum%2!=0) return false;
        int target = totSum/2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,false));

        for(int i=0;i<n;i++) dp[i][0] = true;

        for(int ind=n-1;ind>=0;ind--){
            for(int tar=1;tar<=target;tar++){
                bool notPick = false, pick = false;
                if(ind+1<n) notPick = dp[ind+1][tar];
                if(ind+1<n && tar-nums[ind]>=0) pick = dp[ind+1][tar-nums[ind]];

                dp[ind][tar] = (pick || notPick);
            }
        }

        return dp[0][target];
    }
};