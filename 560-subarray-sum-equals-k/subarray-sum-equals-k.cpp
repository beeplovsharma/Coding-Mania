class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        map<int,int> mp;
        mp.insert({0,1});
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];

            if(mp.find(prefixSum-k)!=mp.end()){
                ans += mp[prefixSum-k];
            }

            mp[prefixSum]++;
        }
        return ans;
    }
};