class Solution {
public:
    typedef long long ll;
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        ll maxi = 0;
        ll maxDiff = 0;
        ll ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,maxDiff * 1LL * nums[i]);
            maxDiff = max(maxDiff,maxi-nums[i]);
            maxi = max(maxi,(ll)nums[i]);
        }
        return ans;
    }
};