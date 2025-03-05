class Solution {
public:
    bool bs(vector<int>& matrix, int target){
        int lo = 0, hi = matrix.size()-1;
        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;
            if(target<=matrix[mid]) hi=mid;
            else lo = mid;
        }
        if(target==matrix[lo] || target==matrix[hi]) return true;

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>nums;
        int n = matrix.size(), m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(matrix[i][j]);
            }
        }

        return bs(nums,target);
    }
};