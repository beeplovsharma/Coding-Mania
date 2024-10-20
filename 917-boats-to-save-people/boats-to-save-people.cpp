class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        int n = nums.size();
        int i=0,j=n-1;
        sort(nums.begin(),nums.end());
        int cnt = 0;
        while(i<=j){
            if(nums[i]+nums[j]<=limit)  i++,j--,cnt++;
            else if(nums[j]<=limit) j--,cnt++;
            else if(nums[i]<=limit) i++,cnt++;
        }
        return cnt;
    }
};