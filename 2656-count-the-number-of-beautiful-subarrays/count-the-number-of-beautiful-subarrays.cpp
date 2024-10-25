class Solution {
public:
#define ll long long
    long long beautifulSubarrays(vector<int>& nums) {
        // set<int>st;
        // st.insert(0);
        map<int,int>mp;
        mp[0]++;
        int i=0,n=nums.size();
        int xr = 0;
        ll cnt=0;
        while(i<n){
            xr = xr ^ nums[i];
            if(mp.find(xr)!=mp.end()){
                cnt+=mp[xr];
            }

            mp[xr]++;
            i++;
        }
        return cnt;
    }
};