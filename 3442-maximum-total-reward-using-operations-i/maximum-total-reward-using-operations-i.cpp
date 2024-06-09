class Solution {
public:
    int solve(vector<int>& rewardValues,int ind,int curr,vector<vector<int>>& dp){
        if(ind == rewardValues.size()){
            return curr;
        }

        if(dp[ind][curr]!=-1) return dp[ind][curr];

        int pick = 0;
        if(curr < rewardValues[ind]){
            pick = solve(rewardValues,ind+1,curr+rewardValues[ind],dp);
        }
        int notPick = solve(rewardValues,ind+1,curr,dp);

        return dp[ind][curr] = max(pick,notPick);
    }

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        int n = rewardValues.size();
        vector<vector<int>>dp(n,vector<int>(4000,-1));
        return solve(rewardValues,0,0,dp);
    }
};