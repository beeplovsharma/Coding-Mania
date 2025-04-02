class Solution {
public:
    typedef long long ll;
    long long maximumTripletValue(vector<int>& nums) {
        ll maxi = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    ll sum = (nums[i]-nums[j]);
                    if(sum<0) sum = 0;
                    sum = sum * nums[k];

                    maxi = max(maxi,sum);
                }
            }
        }

        return maxi<0 ? 0 : maxi;
    }
};