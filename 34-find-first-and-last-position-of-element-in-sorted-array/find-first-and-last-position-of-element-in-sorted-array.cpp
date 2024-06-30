class Solution {
public:

int lbound(vector<int>&v,int x){
    int low = 0;
    int high = v.size()-1;
    int ans = 0;
    while(low<=high){
        int mid= (low+high)/2;

        if(x<=v[mid]){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int ubound(vector < int > & v, int key) {
  int start = 0;
  int end = v.size() - 1;
  int res = -1;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == key) {
      res = mid;
      start = mid + 1;

    } else if (key < v[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return res;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lbound(nums,target);
        int ub = ubound(nums,target);

        if(lb==n || nums[lb]!=target) return {-1,-1};

        return {lb,ub};
    }
};