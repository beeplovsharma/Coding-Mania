class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int tuple = 0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                set<int>st;
                int p = (nums[i]*nums[j]);
                for(int k=i+1;k<j;k++){
                    if(p%nums[k]==0){
                        int val = p/nums[k];

                        if(st.find(val)!=st.end()) tuple++;

                        st.insert(nums[k]);
                    }
                }
            }
        }

        return tuple*8;
    }
};