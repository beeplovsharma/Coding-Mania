class Solution {
public:
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int x = abs(nums[i]-nums[j]);
                    int y = abs(nums[k]-nums[j]);
                    int z = abs(nums[i]-nums[k]);

                    if(x<=a && y<=b && z<=c) cnt++;
                }
            }
        }
        return cnt;
    }
};