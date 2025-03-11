class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int i=0;
        int j=0;
        int n = nums.size();
        int divbyp = 0, cnt=0;
        set<vector<int>>st;
        
        while(j<n){
            if(nums[j]%p==0) divbyp++;

            while(i<=j && divbyp>k){
                if(nums[i]%p==0) divbyp--;
                i++;
            }
            
            vector<int>subarr;
            for(int x=j;x>=i;x--){
                subarr.push_back(nums[x]);
                st.insert(subarr);
            }

            j++;
        }
        return st.size();
    }
};