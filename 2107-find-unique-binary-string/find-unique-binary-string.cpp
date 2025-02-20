class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st;
        int n = nums[0].size();

        for(int i=0;i<(1<<n);i++){
            string s = "";
            for(int j=0;j<n;j++){
                if(i&(1<<j)) s+='1';
                else s+='0';
            }
            st.insert(s);
        }

        for(auto x:nums){
            st.erase(x);
        }

        return *st.begin();
    }
};