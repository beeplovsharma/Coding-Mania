class Solution {
public:
    int countSubarray(vector<int>& arr, int goal){
        int l = 0, r = 0;
        int n = arr.size();
        int sum = 0, cnt = 0;
        while(r<n){
            sum = sum + arr[r];

            while(l<=r && sum>goal){
                sum -= arr[l];
                l++;
            }

            if(sum <= goal) cnt += r-l+1;

            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int x = countSubarray(nums,goal);
        int y = countSubarray(nums,goal-1);

        return (x-y);
    }
};