class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0,high=n-1;

        int flag=-1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==target){
                flag = mid;
                break;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }

        int l=flag,r=flag;
        while(l>0){
            if(nums[l-1]!=target){
                break;
            }
            l--;
        }
        while(r<n-1){
            if(nums[r+1]!=target){
            break;
            }
            r++;
        }

        return {l,r};
    }
};