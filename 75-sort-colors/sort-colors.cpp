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

        for(int i=0;i<nums.size();i++){
            if(i<zero) nums[i]=0;
            else if(zero<=i && i<zero+one) nums[i]=1;
            else nums[i]=2;
        }

    }
};