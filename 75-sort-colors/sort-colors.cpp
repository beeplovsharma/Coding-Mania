class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &x:nums){
            mp[x]++;
        }

        int zero = mp[0];
        int one = mp[1];
        int two = mp[2];

        for(int i=0;i<zero;i++) nums[i]=0;
        for(int i=zero;i<zero+one;i++) nums[i]=1;
        for(int i=zero+one;i<zero+one+two;i++) nums[i]=2;

    }
};