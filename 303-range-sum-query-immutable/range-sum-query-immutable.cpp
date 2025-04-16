class NumArray {
public:
    int n;
    vector<int>prefix;
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        prefix.resize(n);

        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i]=sum;
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right]-(left-1>=0 ? prefix[left-1]:0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */