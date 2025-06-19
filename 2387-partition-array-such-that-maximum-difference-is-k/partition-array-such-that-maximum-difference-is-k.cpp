class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n){
            int j = i;
            bool flag = false;
            while(j<n && (nums[j]-nums[i])<=k){
                j++;
                flag = true;
            }

            if(flag) cnt++;
            else return 0;

            i=j;

        }

        return cnt;
    }
};