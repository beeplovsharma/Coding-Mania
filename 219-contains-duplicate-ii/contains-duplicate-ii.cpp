class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0;
        int n = nums.size();
        map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;

            if(abs(i-j)>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            if(mp[nums[j]]>1) return true;
            
            j++;
        }
        return false;
    }
};