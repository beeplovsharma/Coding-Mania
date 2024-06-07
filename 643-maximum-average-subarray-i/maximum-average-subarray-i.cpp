class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i;
        int sum = 0;
        for(i=0;i<k;i++){
            sum += nums[i];
        }
        int ans = sum;
        int l = 0, r = i;
        int n = nums.size();
        while(r<n){
            sum = sum - nums[l];
            sum = sum + nums[r];

            ans = max(sum,ans);

            l++;
            r++;
        }
        double maxx = (double)ans/k;
        return maxx;
    }
};