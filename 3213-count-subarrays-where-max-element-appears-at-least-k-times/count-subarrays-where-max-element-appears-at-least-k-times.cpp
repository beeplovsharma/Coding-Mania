class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        ll cnt = 0;
        ll i=0,j=0;
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        unordered_map<int,ll>mp;
        while(j<n){
            mp[nums[j]]++;

            while(i<=j && mp[maxi]==k){
                cnt+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            j++;
        }

        return cnt;
    }
};