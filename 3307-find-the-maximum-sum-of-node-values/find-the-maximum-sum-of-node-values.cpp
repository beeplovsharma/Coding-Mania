class Solution {
public:
    typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll count = 0;
        ll sum = 0;
        ll minLoss = LLONG_MAX;  // Use LLONG_MAX for long long

        for (int i = 0; i < nums.size(); i++) {
            int xorr = nums[i] ^ k;
            if (xorr > nums[i]) {
                sum += xorr;
                count++;
                minLoss = min(minLoss, (ll)(xorr - nums[i]));
            } else {
                sum += nums[i];
                minLoss = min(minLoss, (ll)(nums[i] - xorr));
            }
        }

        if (count % 2 == 0) return sum;

        return sum - minLoss;
    }
};
