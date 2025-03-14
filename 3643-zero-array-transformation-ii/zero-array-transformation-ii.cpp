class Solution {
public:
    bool checkZero(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) return false;
        }
        return true;
    }

    bool checkZeroTillMid(vector<int>& nums, vector<vector<int>>& queries, int tar){
        int n = nums.size();
        vector<int>diffArr(n+1,0);

        for(int i=0;i<=tar;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diffArr[l]+=val;
            diffArr[r+1]-=val;
        }

        for(int i=1;i<n;i++) diffArr[i] += diffArr[i-1];

        for(int i=0;i<n;i++){
            if(diffArr[i]<nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int Q = queries.size();

        if(checkZero(nums)) return 0;

        int lo = 0, hi = Q-1;

        while(hi-lo>1){
            int mid = lo+(hi-lo)/2;

            if(checkZeroTillMid(nums,queries,mid)) hi = mid;
            else lo = mid;
        }

        if(checkZeroTillMid(nums,queries,lo)) return lo+1;
        if(checkZeroTillMid(nums,queries,hi)) return hi+1;

        return -1;

    }
};