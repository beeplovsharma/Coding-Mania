class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll count = 0;
        ll sum = 0;
        ll nuksaan = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int xorr = nums[i]^k;
            if(xorr>nums[i]){
                sum += xorr;
                count++;
                nuksaan = min(nuksaan,(ll)(abs(xorr-nums[i])));
            }else{
                sum+=nums[i];
                nuksaan = min(nuksaan,(ll)(abs(xorr-nums[i])));
            }
        }

        if(count%2==0) return sum;

        return sum-nuksaan;
    }
};