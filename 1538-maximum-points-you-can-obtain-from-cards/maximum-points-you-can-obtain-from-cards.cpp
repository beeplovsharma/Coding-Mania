class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        int n = nums.size();
        int l = k-1 , r= n-1;
        int maxx = sum;
        while(l>=0){
            sum = sum - nums[l];
            l--;
            sum = sum + nums[r];
            r--;

            maxx = max(maxx,sum);
        }
        return maxx;
    }
};