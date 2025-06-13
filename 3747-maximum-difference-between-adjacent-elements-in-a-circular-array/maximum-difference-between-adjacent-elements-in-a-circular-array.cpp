class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> doubledArr(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            doubledArr[i] = nums[i % n]; // simulate circular behavior
        }

        int maxi = INT_MIN;

        for(int i=1;i<2*n;i++){
            maxi = max(maxi,abs(doubledArr[i]-doubledArr[i-1]));
        }

        return maxi;
    }
};