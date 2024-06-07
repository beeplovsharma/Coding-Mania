class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int i;
        map<int,int>mp;
        for(i = 0;i<k;i++){
            mp[nums[i]]++;
            sum = sum + nums[i];
        }
        long long ans = 0;
        if(mp.size()==k) ans = sum;

        int l = 0, r=i;
        int n = nums.size();
        while(r<n){
            mp[nums[l]]--;
            mp[nums[r]]++;

            if(mp[nums[l]]==0) mp.erase(nums[l]);

            sum = sum - nums[l];
            sum = sum + nums[r];
            
            if(mp.size()==k) ans = max(sum,ans);

            l++;
            r++;
        }
        return ans;
    }
};