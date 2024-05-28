class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int searchElem = target - nums[i];
            if(mp.find(searchElem)!=mp.end()){
                return {mp[searchElem],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};