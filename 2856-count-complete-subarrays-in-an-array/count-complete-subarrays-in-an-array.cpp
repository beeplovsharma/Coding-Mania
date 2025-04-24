class Solution {
public:
    int fun(vector<int>& nums,int k){
        int i=0,j=0;
        int n = nums.size();
        unordered_map<int,int>mp;
        int count = 0;
        while(j<n){
            mp[nums[j]]++;
            
            while(i<=j && mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }

            count += j-i+1;
            j++;
        }
        return count;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        for(auto &x:nums) st.insert(x);
        int distinct = st.size();

        return fun(nums,distinct)-fun(nums,distinct-1);
    }
};