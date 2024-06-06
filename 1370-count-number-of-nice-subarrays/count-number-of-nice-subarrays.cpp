class Solution {
public:
    int countSubarray(vector<int>& nums, int k){
        int l = 0, r = 0;
        int n = nums.size();
        int odd = 0;
        int cnt = 0;
        while(r<n){
            if(nums[r]%2!=0) odd++;
            
            while(odd>k){
                if(nums[l]%2!=0) odd--;
                l++;
            }
            
            if(odd<=k) cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int x = countSubarray(nums,k);
        int y = countSubarray(nums,k-1);

        return (x-y);
    }
};