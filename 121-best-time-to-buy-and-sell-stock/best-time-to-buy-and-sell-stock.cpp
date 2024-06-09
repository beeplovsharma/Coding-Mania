class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini = arr[0], profit = 0;
        int n = arr.size();
        for(int i=1;i<n;i++){
            int cost = arr[i] - mini;
            profit = max(profit,cost);
            mini = min(mini,arr[i]);
        }
        return profit;
    }
};