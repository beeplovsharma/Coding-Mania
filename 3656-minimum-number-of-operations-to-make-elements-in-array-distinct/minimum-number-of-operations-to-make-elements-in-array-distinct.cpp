class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        int seen = -1;
        for(int i=n-1;i>=0;i--){
            if(st.find(nums[i])!=st.end()){
                seen = i;
                break;
            }
            st.insert(nums[i]);
        }

        return ceil((seen+1)/3.0);
    }
};