class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto &x:nums) mp[x]++;

        multiset<int>ms;
        for(auto &x:mp) ms.insert(x.second);

        int cnt = 0;
        for(auto &x:ms){
            cout<<x<<" ";
            if(x<=k){
                cnt++;
                k-=x;
            }

            if(k==0) break;
        }

        return mp.size()-cnt;
    }
};