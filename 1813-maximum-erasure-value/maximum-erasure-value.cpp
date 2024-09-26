class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int n = nums.size();
        int sum = 0,maxi=INT_MIN;

        map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            sum = sum+nums[j];
            

            while(mp[nums[j]]>1){
                mp[nums[i]]--;
                sum = sum - nums[i];
                i++;
            }

            maxi = max(maxi,sum);
            j++;
        }

        return maxi;
    }
};