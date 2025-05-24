class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1;
        int end = -1;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(i+1<n && nums[i]>nums[i+1]){
                start = i;
                break;
            }
        }

        // If already sorted
        if(start == -1) return 0;

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                end = i+1;
                break;
            }
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=start;i<=end;i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }

        // Extend start to the left if needed
        while(start > 0 && nums[start - 1] > mini){
            start--;
        }

        // Extend end to the right if needed
        while(end < n - 1 && nums[end + 1] < maxi){
            end++;
        }

        return end - start + 1;
    }
};