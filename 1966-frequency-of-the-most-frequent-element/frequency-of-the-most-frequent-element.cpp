class Solution {
public:
    int bs(int target_idx,vector<int>& nums, int k,vector<long>&prefix){
        int l=0,r=target_idx;
        int res = 0;
        int tar = nums[target_idx];
        int best_idx = target_idx;

        while(l<=r){
            int mid = l + (r-l)/2;
            long count = (target_idx-mid+1);
            long required_sum = tar * count;
            long actual_sum = prefix[target_idx] - prefix[mid] + nums[mid];
            int diff = required_sum - actual_sum;

            if(diff > k) l = mid+1;
            else {
                best_idx = mid;
                r = mid-1;
            }
        }

        return target_idx - best_idx + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<long>prefix(n,0);

        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int freq = bs(i,nums,k,prefix);
            maxi = max(maxi,freq);
        }
        return maxi;
    }
};