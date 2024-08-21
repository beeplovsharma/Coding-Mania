class Solution {
public:
#define ll long long
    vector<int> getAverages(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        k = 2*k+1;
        ll sum = 0;
        vector<int>ans(n,-1);
        while(j<n){
            sum += nums[j];

            if(j-i+1 == k){
                int ind = k/2+i;
                ans[ind] = (int)(sum/k);

                sum-=nums[i];
                i++;
            }

            j++;
        }
        return ans;
    }
};