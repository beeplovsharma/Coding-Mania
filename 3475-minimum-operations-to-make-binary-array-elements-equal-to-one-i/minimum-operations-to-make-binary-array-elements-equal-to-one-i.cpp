class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            if(nums[i]==1) continue;

            for(int j=i;j<=i+2;j++){
                nums[j] = nums[j]^1;
            }
            cnt++;
        }

        for(int i=0;i<n;i++){
            if(nums[i]==0) return -1;
        }

        return cnt;
    }
};