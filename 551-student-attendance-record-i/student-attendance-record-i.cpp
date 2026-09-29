class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();

        int P=0,A=0,L=0;

        for(int i=0;i<n;i++){
            if(L>2 || A>1) return false;
            
            if(s[i]=='P') P++, L=0;
            else if(s[i]=='A') A++, L=0;
            else L++;
        }

        return (A<=1 && L<=2);
    }
};