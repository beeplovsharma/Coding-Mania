class Solution {
public:
    int fun(int n){
        int dig = 0;
        while(n){
            n=n/10;
            dig++;
        }
        return dig;
    }
    int findNumbers(vector<int>& nums) {
        int even = 0;
        for(int i=0;i<nums.size();i++){
            if(fun(nums[i])%2==0) even++;
        }
        return even;
    }
};