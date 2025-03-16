class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(i+1 < n && (i-cnt)%2==0 && nums[i]==nums[i+1]){
                cnt++;
            }
        }
        return (nums.size()-cnt)%2==0 ? cnt : cnt+1;
    }
};