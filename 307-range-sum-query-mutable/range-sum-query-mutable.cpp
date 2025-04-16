class NumArray {
public:
    int n;
    vector<int>seg;
    void buildSegment(vector<int>&nums,int i,int l,int r){
        if(l==r){
            seg[i] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        buildSegment(nums,2*i+1,l,mid);
        buildSegment(nums,2*i+2,mid+1,r);

        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    void updateSegment(int i,int l,int r,int idx,int val){
        if(l==r){
            seg[i] = val;
            return; 
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            updateSegment(2*i+1,l,mid,idx,val);
        }else{
            updateSegment(2*i+2,mid+1,r,idx,val);
        }

        seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int querySum(int i,int l,int r,int start,int end){
        if(start>r || end<l) return 0;
        if(start<=l && r<=end) return seg[i];

        int mid = (l+r)/2;
        int left = querySum(2*i+1,l,mid,start,end);
        int right = querySum(2*i+2,mid+1,r,start,end);
        return left + right;
    }

    NumArray(vector<int>& nums) {
        this->n = nums.size();
        seg.resize(4 * n, 0);
        buildSegment(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        updateSegment(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return querySum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */