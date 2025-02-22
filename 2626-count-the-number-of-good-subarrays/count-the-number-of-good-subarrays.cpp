class Solution {
public:
    #define ll long long
    long long countGood(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        ll pair = 0;
        ll ans = 0;
        map<int,int>mp;
        int l = 0;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            pair += mp[nums[j]]-1;

            while(i<=j && pair>=k){
                ans+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]>=1) pair-=mp[nums[i]];
                i++;
            }
        }
        return ans;
    }
};