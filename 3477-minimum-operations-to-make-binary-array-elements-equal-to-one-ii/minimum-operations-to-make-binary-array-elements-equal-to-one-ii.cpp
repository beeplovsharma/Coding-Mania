class Solution {
public:
    int feasible(vector<int>& nums,int k){
        int flips = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0 && flips==0){
                flips++;
            }

            if(flips%2==nums[i]) flips++;

            if(flips>k) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int lo=0,hi=1e5;
        int n = nums.size();
        while(hi-lo>1){
            int mid = lo+(hi-lo)/2;

            if(feasible(nums,mid)) hi = mid;
            else lo = mid;
        }

        if(feasible(nums,lo)) return lo;
        if(feasible(nums,hi)) return hi;

        return -1;
    }
};