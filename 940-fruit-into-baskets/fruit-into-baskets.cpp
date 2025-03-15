class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        unordered_map<int,int>mp;
        int maxi = 0;
        while(j<n){
            mp[nums[j]]++;
            
            while(mp.size()>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;
    }
};