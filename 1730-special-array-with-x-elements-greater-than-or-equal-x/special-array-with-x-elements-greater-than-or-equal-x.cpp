class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        int cnt;
        for(int i=1;i<=n;i++){
            cnt = 0;
            for(int j=0;j<n;j++){
                if(i<=nums[j]) cnt++;
            }
            if(cnt==i) return i;
        }
        return -1;
    }
};