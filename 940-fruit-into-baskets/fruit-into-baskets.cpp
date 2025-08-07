class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int maxi = 0;
        unordered_map<int,int>mp;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            while(i<n && mp.size()>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            maxi = max(maxi,j-i+1);
        }

        return maxi;
    }
};