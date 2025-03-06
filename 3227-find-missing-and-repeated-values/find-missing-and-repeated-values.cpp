class Solution {
public:
    #define ll long long
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        ll sum = 0;
        ll sqSum = 0;

        int n = grid.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
                sqSum += grid[i][j] * grid[i][j];
            }
        }

        int len = n*n;
        ll perfectSum = (len)*(len+1)/2;
        ll perfectSqSum = (len)*1LL*(len+1)*(2*len+1)/6;

        ll sumDiff = sum - perfectSum;
        ll sqDiff = sqSum - perfectSqSum;

        int repeat = (sqDiff / sumDiff + sumDiff) / 2;
        int missing = (sqDiff / sumDiff - sumDiff) / 2;

        return {repeat,missing};

    }
};