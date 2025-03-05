class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lo = 0;
        int hi = n*m-1;

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col]<=target) lo = mid;
            else hi=mid;
        }

        if(matrix[lo/m][lo%m]==target) return true;
        if(matrix[hi/m][hi%m]==target) return true;

        return false;
    }
};