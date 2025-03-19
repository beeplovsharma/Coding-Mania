class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int cntFlip = 0;
        vector<bool>isFlipped(n,0);
        int flips = 0;

        for(int i=0;i<n;i++){

            if(nums[i]==0 && cntFlip==0 && i+k<=n){
                cntFlip++;
                isFlipped[i]=true;
                flips++;
            }

            if(i-k>=0 && isFlipped[i-k]==true){
                cntFlip--;
            }

            if(cntFlip%2==nums[i]){
                if(i+k>n) return -1;
                cntFlip++;
                isFlipped[i]=true;
                flips++;
            }
        }

        return flips;
    }
};