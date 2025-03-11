class Solution {
public:
    int fun(vector<int>& nums, int k){
        int i=0,j=0;
        int n = nums.size();
        int cnt = 0;
        map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;

            while(i<=j && mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};