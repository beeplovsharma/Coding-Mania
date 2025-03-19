class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cntFlip = 0;
        int flips = 0;
        vector<bool>isFlipped(n,0);

        for(int i=0;i<n;i++){
            if(i>=k && isFlipped[i-k]==true){
                cntFlip--;
            }

            if((cntFlip%2==nums[i])){
                if(i+k>n) return -1;

                cntFlip++;
                flips++;
                isFlipped[i] = true;
            }
        }

        return flips;
    }
};