class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>diffArr(n,0);
        for(auto &shift:shifts){
            int l = shift[0];
            int r = shift[1];
            int val = shift[2]==0 ? -1 : 1;

            diffArr[l]+=val;
            if(r+1<n) diffArr[r+1]-=val;
        }
        for(int i=1;i<n;i++) diffArr[i]+=diffArr[i-1];

        for(int i=0;i<n;i++){
            int shiftIdx = (diffArr[i]%26+26)%26;
            s[i] = 'a' + (s[i]-'a'+shiftIdx)%26;
        }

        return s;
    }
};