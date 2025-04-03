class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        int i=0,j=n-1;
        vector<pair<int,int>>nums(n);
        for(int i=0;i<n;i++) nums[i] = {arr[i],i};
        sort(nums.begin(),nums.end());
        while(i<j){
            if(nums[i].first+nums[j].first==target) return {nums[i].second,nums[j].second};
            else if(nums[i].first+nums[j].first<target) i++;
            else j--;
        }
        return {-1,-1};
    }
};