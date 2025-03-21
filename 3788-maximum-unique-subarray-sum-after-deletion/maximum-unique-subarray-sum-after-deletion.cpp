class Solution {
public:
    int maxSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        bool flag = true;
        for(auto x:nums){
            if(x>0){
                flag = false;
                break;
            }
        }
        if(flag) return *max_element(nums.begin(),nums.end());
        
        set<int>st;

        for(auto x:nums){
            if(x>0) st.insert(x);
        }

        int ans = 0;
        for(auto x:st){
            ans += x;
        }

        return ans;
    }
};