class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, long long k) {
        int i=0,j=0;
        int n = nums.size();
        ll maxi=INT_MIN;
        ll sum=0,score=0;
        ll cnt = 0;
        while(j<n){
            sum+=nums[j];

            while(i<=j && sum*(j-i+1)>=k){
                sum-=nums[i];
                i++;
            }

            cnt+=j-i+1;
            j++;
        }

        return cnt;
    }
};