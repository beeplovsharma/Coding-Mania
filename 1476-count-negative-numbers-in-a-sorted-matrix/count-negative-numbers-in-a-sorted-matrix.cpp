class Solution {
public:
    int bs(vector<int>&v){
        int lo=0,hi=v.size()-1;

        while(hi-lo>1){
            int mid = (lo+hi)/2;

            if(v[mid]<0) hi=mid;
            else lo=mid+1;
        }

        if(v[lo]<0) return lo;
        if(v[hi]<0) return hi;

        return -1;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(auto &v:grid){
            int ind = bs(v);
            if(ind!=-1) ans += m-ind;
        }
        return ans;
    }
};