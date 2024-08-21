class Solution {
public:
    int calcSum(vector<int>& nums,int start,int end){
        int sum = 0;
        for(int i=start;i<=end;i++){
            sum+=nums[i];
        }
        return sum;
    }
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
    vector<int> ans(n, -1); // Initialize result with -1
    
    if (n < 2 * k + 1) {
        return ans; // Not enough elements to calculate any average
    }
    
    long long windowSum = 0;
    int windowSize = 2 * k + 1;
    
    // Calculate initial window sum
    for (int i = 0; i < windowSize; ++i) {
        windowSum += nums[i];
    }
    
    // Calculate averages using sliding window
    for (int i = k; i < n - k; ++i) {
        ans[i] = windowSum / windowSize;
        if (i + k + 1 < n) {
            windowSum += nums[i + k + 1] - nums[i - k];
        }
    }
    
    return ans;
    }
};