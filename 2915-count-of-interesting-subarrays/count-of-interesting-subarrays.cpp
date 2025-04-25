class Solution {
public:
    typedef long long ll;
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        vector<int>hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=(nums[i]%m==k)?1:0;
        }

        unordered_map<int,ll>mp;
        mp[0]=1;
        ll s1 = 0;
        ll ans = 0;
        for(int i=0;i<n;i++){
            s1+=hash[i];
            int r1 = s1%m;
            int r2 = (r1-k+m)%m;
            if(mp.count(r2)) ans+=mp[r2];
            mp[r1]++;
        }
        return ans;

    }
};