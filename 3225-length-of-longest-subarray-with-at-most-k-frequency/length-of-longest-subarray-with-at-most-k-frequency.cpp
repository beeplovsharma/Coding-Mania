class Solution {
public:
    // bool checkK(map<int,int>&mp,int k){
    //     for(auto x:mp){
    //         if(x.second > k) return true;
    //     }

    //     return false;
    // }
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>freq;

        int n = nums.size();
        int i=0;
        int j=0;

        int maxx = 0;

        while(j<n){
            freq[nums[j]]++;

            while(freq[nums[j]]>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0) freq.erase(nums[i]);
                i++;
            }

            maxx = max(maxx,j-i+1);
            j++;
        }

        return maxx;
    }
};