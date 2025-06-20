class Solution {
public:
    int maxDistance(string s, int k) {
        int east = 0, west = 0, north = 0, south = 0;
        int n = s.size();
        int maxMD = INT_MIN;

        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch=='N') north++;
            else if(ch=='S') south++;
            else if(ch=='E') east++;
            else west++;

            int x = abs(east-west);
            int y = abs(north-south);

            int steps = i+1;
            int curMD = abs(x) + abs(y);
            int wasted = steps - curMD;

            int inc = min(wasted,2*k);

            maxMD = max(maxMD,curMD+inc);
        }

        return maxMD;
    }
};