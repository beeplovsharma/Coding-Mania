class Solution {
public:
#define ll long long
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n,-1);
        if(n < 2*k+1) return ans;

        vector<ll>prefix;
        ll pre_sum = 0;
        for(int i=0;i<nums.size();i++){
            pre_sum += nums[i];
            prefix.push_back(pre_sum);
        }

        for(int i=k;i<n-k;i++){
            ll sum = prefix[i+k];
            if(i-k > 0){
                sum -= prefix[i-k-1];
            }
            ans[i] = (int)(sum/(2*k+1));
        }
        return ans;
    }
};