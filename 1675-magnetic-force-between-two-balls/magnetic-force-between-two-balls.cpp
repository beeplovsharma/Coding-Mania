class Solution {
public:
    bool feasible(vector<int>& nums,int k, int m){
        int cnt = 1, n = nums.size();
        int last = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-last>=k){
                cnt++;
                last=nums[i];
            }
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lo = 1;
        int hi = (nums[n-1]-nums[0]);

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(feasible(nums,mid,m)) lo=mid;
            else hi=mid;
        }

        if(feasible(nums,hi,m)) return hi;
        if(feasible(nums,lo,m)) return lo;

        return -1;
    }
};