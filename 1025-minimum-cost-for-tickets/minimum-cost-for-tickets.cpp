class Solution {
public:
    int N;
    int dp[366];
    int check(int ind, int day, vector<int>& days){
        int tar = days[ind]+day;
        auto it = lower_bound(days.begin(),days.end(),tar);
        return it-days.begin();
    }

    int fun(int ind,vector<int>& days, vector<int>& costs){
        if(ind>=N) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int ans = 1e9;
        int indexForOneDay = check(ind,1,days);
        ans = min(ans,costs[0]+fun(indexForOneDay,days,costs));

        int indexForSevenDay = check(ind,7,days);
        ans = min(ans,costs[1]+fun(indexForSevenDay,days,costs));

        int indexForThirtyDay = check(ind,30,days);
        ans = min(ans,costs[2]+fun(indexForThirtyDay,days,costs));

        return dp[ind] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        N = days.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,days,costs);
    }
};