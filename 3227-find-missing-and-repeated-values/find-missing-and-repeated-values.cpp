class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[grid[i][j]]++;
            }
        }

        int a,b;
        for(int i=0;i<n*n;i++){
            if(mp.find(i+1)==mp.end()) b=i+1;
            if(mp[i+1]==2) a=i+1;
        }
        return {a,b};
    }
};