class ProductOfNumbers {
public:
    vector<int>nums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            nums.clear();
        }
        else{
            if(nums.size()==0) nums.push_back(num);
            else{
                int prod = nums.back() * num;
                nums.push_back(prod);
            }
        }
    }
    
    int getProduct(int k) {
        if(k>nums.size()) return 0;

        int n = nums.size();
        if(k==nums.size()) return nums[n-1];

        return nums[n-1]/nums[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */