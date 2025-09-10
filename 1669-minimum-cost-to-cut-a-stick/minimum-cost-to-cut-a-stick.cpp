class Solution {
public:
    int dp[101][101];
    int fun(vector<int>& cuts, int i ,int j){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = 1e9;
        for(int ind=i;ind<=j;ind++){
            int cost = (cuts[j+1]-cuts[i-1])+fun(cuts,i,ind-1)+fun(cuts,ind+1,j);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        n = cuts.size();

        return fun(cuts,1,n-2);
    }
};