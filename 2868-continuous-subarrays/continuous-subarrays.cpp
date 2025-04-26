class Solution {
public:
    typedef long long ll;
    long long continuousSubarrays(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        ll count = 0;
        multiset<int>mst;
        while(j<n){
            mst.insert(nums[j]);

            while(i<=j && abs(*mst.begin()-*mst.rbegin())>2){
                mst.erase(mst.find(nums[i]));
                i++;
            }

            count+=j-i+1;
            j++;
        }
        return count;
    }
};