class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini = arr[0];
        int profit = 0;
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(profit < arr[i]-mini)
                profit = arr[i]-mini;

            if(mini > arr[i])
                mini = min(mini,arr[i]);
        }
        return profit;
    }
};