class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>mp1,mp2,common;
        int n = tops.size();
        for(int i=1;i<=6;i++) common[i]=0;
        for(int i=0;i<n;i++){
            mp1[tops[i]]++;
            mp2[bottoms[i]]++;
            if(tops[i]==bottoms[i]) common[tops[i]]++;
        }
        int mini = INT_MAX;
        for(int i=1;i<=6;i++){
            int curr = mp1[i]+mp2[i]-common[i];
            if(curr==n){
                mini = min(mini,min(mp1[i],mp2[i])-common[i]);
            }
        }

        return mini==INT_MAX ? -1 : mini;
    }
};