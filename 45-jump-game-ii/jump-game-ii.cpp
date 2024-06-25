class Solution {
public:
//     int recursion(vector<int>& nums, int ind, int jumps) {
//         int n = nums.size();
//         if (ind >= n - 1) {
//             return jumps;
//         }
//         int minSteps = INT_MAX;
    
//         for (int j = 1; j <=  nums[ind]; ++j) {
//             if (ind + j < n) {
//                 minSteps = min(minSteps, solve(nums, ind + j, jumps + 1));
//             }
//         }
//         return minSteps;
// }
    int greedy(vector<int>& nums){
        int l = 0, r = 0;
        int n = nums.size();
        int cnt = 0;
        while(r<n-1){
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest,nums[i]+i);
            }
            l = r+1;
            r = farthest;
            cnt++;
        }
        return cnt;
    }
    int jump(vector<int>& nums) {
        // recursion(nums,0,0);
        return greedy(nums);
    }
};