class Solution {
public:
    bool checkDistinct(unordered_map<int,int>&mp){
        for(auto &x:mp){
            if(x.second>1) return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto &x:nums) mp[x]++;


        int cnt = 0;
        int i=0;
        while(i<n){
            if(checkDistinct(mp)) break;
            int j=0;
            while(i+j<n && j<3){
                int el = nums[i+j];
                mp[el]--;
                if(mp[el]==0) mp.erase(el);
                j++;
            }
            cnt++;
            i=i+3;
        }
        return cnt;
    }
};