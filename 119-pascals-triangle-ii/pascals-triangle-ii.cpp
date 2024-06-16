class Solution {
#define ll long long
public:

    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ll mul = 1;
        ans.push_back(mul);
        for(int i=1;i<rowIndex+1;i++){
            mul = mul * (rowIndex-i+1);
            mul = mul / i;
            ans.push_back(mul);
        }
        return ans;
    }
};