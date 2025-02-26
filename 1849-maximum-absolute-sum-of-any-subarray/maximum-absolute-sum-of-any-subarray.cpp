class Solution {
public:
    int calcMax(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum<0) sum=0;

            maxi = max(maxi,sum);
        }

        return maxi;
    }

    int calcMin(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum>0) sum=0;

            mini = min(mini,sum);
        }

        return mini;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int x = calcMin(nums);
        int y = calcMax(nums);

        return max(abs(x),y);
    }
};