class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        vector<int>pairSum;
        int n = nums.size();
        for(int i=1;i<n;i++){
            pairSum.push_back(nums[i]+nums[i-1]);
        }
        sort(pairSum.begin(),pairSum.end());

        long long lSum = 0;
        long long rSum = 0;

        int i=0,j=pairSum.size()-1;
        k--;
        while(k!=0){
            lSum+=pairSum[i++];
            rSum+=pairSum[j--];
            k--;
        }

        return abs(rSum-lSum);
    }
};