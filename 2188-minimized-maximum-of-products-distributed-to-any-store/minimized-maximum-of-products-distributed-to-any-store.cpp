class Solution {
public:
    bool feasible(vector<int>& nums,int n, int maxx){
        long long cnt = 0;
        for(int i=0;i<nums.size();i++){
            cnt += ceil(nums[i]/(double)maxx);
        }

        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(feasible(nums,n,mid)) hi=mid;
            else lo=mid;
        }

        if(feasible(nums,n,lo)) return lo;
        if(feasible(nums,n,hi)) return hi;

        return -1;
        
    }
};