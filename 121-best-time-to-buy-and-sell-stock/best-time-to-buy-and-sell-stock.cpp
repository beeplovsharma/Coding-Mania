class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int pist = 0;
        int op = INT_MIN;
        int msf = INT_MAX;

        for(int i=0;i<n;i++){
            msf = min(msf,nums[i]);

            pist = nums[i]-msf;
            op = max(op,pist);
        }

        return op;
    }
};