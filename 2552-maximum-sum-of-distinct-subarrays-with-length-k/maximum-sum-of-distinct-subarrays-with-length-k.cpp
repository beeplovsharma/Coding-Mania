class Solution {
public:
    #define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;

        ll sum = 0;
        ll maxi = INT_MIN;
        map<int,int>mp;
        while(j<n){
            sum+=nums[j];
            mp[nums[j]]++;
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(mp.size()==k) maxi = max(maxi,sum);
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return maxi==INT_MIN ? 0 : maxi;
    }
};