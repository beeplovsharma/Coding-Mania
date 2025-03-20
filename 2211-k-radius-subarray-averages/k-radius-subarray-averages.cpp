class Solution {
public:
    typedef long long ll;
    vector<int> getAverages(vector<int>& nums, int k) {
        int win = 2*k+1;
        int i=0,j=0;
        int n = nums.size();
        vector<int>ans(n,-1);
        ll sum = 0;
        while(j<n){
            sum+=nums[j];

            if(j-i+1<win){
                j++;
            }
            else if(j-i+1==win){
                ll avg = sum/win;
                int idx = (i+j)/2;
                ans[idx]=avg;

                sum-=nums[i];
                i++;
                j++;
            }
        }

        return ans;
    }
};