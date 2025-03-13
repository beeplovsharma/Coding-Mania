class Solution {
public:
    typedef long long ll;
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r= 0;
        int n=nums.size();
        ll prod = 1;
        int cnt=0;
        while(r<n){
            prod*=nums[r];

            while(l<=r && prod>=k){
                prod/=nums[l];
                l++;
            }

            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
};