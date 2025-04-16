class Solution {
public:
    #define ll long long
    long long countGood(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int p = 0;
        ll ans = 0;
        unordered_map<int, int> freq;

        while (j < n) {
           p+=freq[nums[j]];
           freq[nums[j]]++;

           while(p>=k){
            ans += n-j;

            p -= (freq[nums[i]]-1);
            freq[nums[i]]--;
            if(freq[nums[i]]==0) freq.erase(nums[i]);
            i++;
           }
            j++;
        }

        return ans;
    }
};
