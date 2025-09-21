class Solution {
public:
    class PW {
    public:
        int lp, rp;
        PW(int a = 0, int b = 0) {
            lp = a;
            rp = b;
        }
    };

    PW fun(vector<int>& nums, int l, int r, int turn){
        if(l==r){
            if (turn == 1) return PW(nums[l], 0);
            else return PW(0, nums[r]);
        }
        
        PW ans;
        if(turn==1){
            PW takeLeft = fun(nums,l+1,r,2);
            takeLeft.lp += nums[l];

            PW takeRight = fun(nums,l,r-1,2);
            takeRight.lp += nums[r];

            ans = takeLeft.lp>=takeRight.lp ? takeLeft : takeRight;
        }else{
            PW takeLeft = fun(nums,l+1,r,1);
            takeLeft.rp += nums[l];

            PW takeRight = fun(nums,l,r-1,1);
            takeRight.rp += nums[r];

            ans = takeLeft.rp>=takeRight.rp ? takeLeft : takeRight;
        }

        return ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        PW ans = fun(nums,0,n-1,1);
        return ans.lp >= ans.rp;
    }
};