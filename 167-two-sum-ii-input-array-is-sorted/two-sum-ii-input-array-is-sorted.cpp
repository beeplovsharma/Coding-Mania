class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int left = 0;
        int right = v.size()-1;

        while(left<right){
            if(v[left]+v[right]==target){
                break;
            }

            else if(v[left]+v[right]<target) left++;

            else right--;
        }

        vector<int>ans = {left+1,right+1};
        return ans;
    }
};