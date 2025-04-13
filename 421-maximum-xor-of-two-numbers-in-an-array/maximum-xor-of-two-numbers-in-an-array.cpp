class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, maxi = 0;

        for(int i=31;i>=0;i--){
            mask = mask | (1<<i);
            set<int>st;
            for(auto num:nums) st.insert(mask&num);

            int tmp = maxi|(1<<i);
            for(auto x:st){
                if(st.find(x^tmp)!=st.end()){
                    maxi = tmp;
                    break;
                }
            }
        }

        return maxi;
    }
};