class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            int curLen = 1;
            int next = nums[i];
            int add = 1;
            for(int j=i+1;j<n;j++){
                next += add;
                if(next==nums[j]){
                    curLen++;
                }
                else{
                    break;
                }
                add = add * (-1);
            }
            ans = max(ans,curLen);
        }
        return ans==1 ? -1 : ans;
    }
};