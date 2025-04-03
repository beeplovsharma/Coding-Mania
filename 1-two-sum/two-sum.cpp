class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int x = target - nums[i];
            if(mp.count(x)){
                return {i,mp[x]};
            }
            mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};