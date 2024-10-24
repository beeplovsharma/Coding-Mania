class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        int xor_all = 0;
        for(int i=0;i<n;i++){
            xor_all ^= nums[i];
        }

        int f_set_bit = 0;
        int temp = xor_all;
        while(temp){
            if(temp&1){
                break;
            }
            else{
                f_set_bit++;
                temp = temp>>1;
            }
        }

        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i] & (1<<f_set_bit)) x = x^nums[i];
        }

        int y = xor_all^x;

        return {x,y};
    }
};