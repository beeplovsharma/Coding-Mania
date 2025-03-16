class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n = s1.size();
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='x')x++;
            else y++;
            if(s2[i]=='y')y++;
            else x++;
        }

        int xy = 0;
        int yx = 0;
        for(int i=0;i<n;i++){
            if((s1[i]=='x' && s2[i]=='y')) xy++;
            if((s1[i]=='y' && s2[i]=='x')) yx++;
        }

        if(xy%2==0 && yx%2==0){
            return (xy/2+yx/2);
        }

        return (x%2==0 && y%2==0) ? ((xy/2+yx/2)) + 2 : -1;
    }
};