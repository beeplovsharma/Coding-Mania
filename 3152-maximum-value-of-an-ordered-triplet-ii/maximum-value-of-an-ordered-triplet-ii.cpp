class Solution {
public:
    typedef long long ll;
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);

        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            leftMax[i] = maxi;
        }

        maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,nums[i]);
            rightMax[i] = maxi;
        }

        ll ans = INT_MIN;
        for(int i=1;i<n-1;i++){
            if((leftMax[i-1]-nums[i]) < 0) continue;
            ll sum = (leftMax[i-1]-nums[i]) * 1LL * rightMax[i+1];
            ans = max(ans,sum);
        }

        return (ans==INT_MIN) ? 0 : ans;
    }
};