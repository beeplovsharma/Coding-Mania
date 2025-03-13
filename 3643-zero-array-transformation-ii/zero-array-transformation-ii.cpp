class Solution {
public:

    bool checkZero(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) return false;
        }
        return true;
    }

    bool checkTillMid(vector<int>& nums, vector<vector<int>>& queries,int mid){
        int n = nums.size();

        vector<int>diffArr(n,0);
        for(int i=0;i<=mid;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diffArr[l]+=val;
            if(r+1<n) diffArr[r+1]-=val;
        }

        for(int i=1;i<n;i++) diffArr[i] = diffArr[i]+diffArr[i-1];

        for(int i=0;i<n;i++){
            if(diffArr[i]<nums[i]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int Q = queries.size();

        if(checkZero(nums)) return 0;

        int lo=0,hi=Q-1;
        int k = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(checkTillMid(nums,queries,mid)){
                k=mid+1;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return k;
        // while(hi-lo>1){
        //     int mid = lo + (hi-lo)/2;

        //     if(checkTillMid(nums,queries,mid)) hi = mid;
        //     else lo = mid;
        // }

        // if(checkTillMid(nums,queries,lo)) return lo+1;
        // if(checkTillMid(nums,queries,hi)) return hi+1;

        // return -1;
    }
};