class Solution {
#define ll long long 
public:
    long long solve(vector<int>& power,int ind,vector<ll>&dp){
        if(ind>=power.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int nextIndex = ind+1;
        long long cnt = 1;
        while(nextIndex<power.size() && power[nextIndex]==power[ind]){
            nextIndex++;
            cnt++;
        }

        long long exclude = solve(power,nextIndex,dp);
        while(nextIndex<power.size() && (power[nextIndex]==power[ind]+1 || power[nextIndex]==power[ind]+2)){
            nextIndex++;
        }
        long long include = (cnt * power[ind]) + solve(power,nextIndex,dp);
        
        return dp[ind] = max(include,exclude);
    }
    
    
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        int n = power.size();
        vector<ll>dp(n,-1);
        return solve(power,0,dp);
    }
};