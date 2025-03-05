class Solution {
public:
    bool bs(vector<vector<int>>& matrix, int target,int row){
        int lo = 0, hi = matrix[0].size()-1;
        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;
            if(target<=matrix[row][mid]) hi=mid;
            else lo = mid;
        }
        if(target==matrix[row][lo] || target==matrix[row][hi]) return true;

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            if(bs(matrix,target,i)) return true;
        }

        return false;
    }
};