class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int>mp;//rem
        mp[0]++;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int rem = (sum%k + k)%k;
            if(mp.count(rem)) cnt+=mp[rem];
            mp[rem]++;
        }
        return cnt;
    }
};