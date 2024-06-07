class Solution {
public:
    int countSubarray(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int,int>mp;
        int cnt = 0;

        while(r<n){
            mp[nums[r]]++;

            while(l<=r && mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }

            if(mp.size()<=k){
                cnt += r-l+1;
            }

            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x = countSubarray(nums,k);
        int y = countSubarray(nums,k-1);

        return (x-y);
    }
};