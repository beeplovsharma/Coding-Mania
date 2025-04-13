class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector<int>v;
        for(int i=0 ;i<(1<<n);i++)
        v.push_back(i^(i>>1));
        return v;
    }
    vector<int> circularPermutation(int n, int start) {
        vector<int>gcode = grayCode(n);
        vector<int>ans;
        int startInd = -1;
        for(int i=0;i<(1<<n);i++){
            if(gcode[i]==start){
                startInd = i;
                break;
            }
        }

        ans.push_back(gcode[startInd]);
        for(int i=startInd+1;;i++){
            int idx = (i%(1<<n));
            if(idx==startInd) break;
            ans.push_back(gcode[idx]);
        }

        return ans;
    }
};