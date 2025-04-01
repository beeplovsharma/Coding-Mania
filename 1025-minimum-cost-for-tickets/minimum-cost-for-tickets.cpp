class Solution {
public:
    int getNextStartDay(vector<int>& days,int start,int target){
        for(int day=start;day<days.size();day++){
            if(days[day]>target) return day;
        }
        return days.size();
    }
    int fun(vector<int>& days, vector<int>& costs,int ind,vector<int>&dp){
        if(ind>=days.size()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int passOne = costs[0] + fun(days,costs,getNextStartDay(days,ind+1,days[ind]+1-1),dp);
        int passTwo = costs[1] + fun(days,costs,getNextStartDay(days,ind+1,days[ind]+7-1),dp);
        int passThree = costs[2] + fun(days,costs,getNextStartDay(days,ind+1,days[ind]+30-1),dp);

        return dp[ind] = min({passOne,passTwo,passThree});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,-1);
        return fun(days,costs,0,dp);
    }
};