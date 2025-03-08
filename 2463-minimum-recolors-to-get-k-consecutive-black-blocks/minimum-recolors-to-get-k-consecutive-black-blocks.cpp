class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0,j=0;
        int n = blocks.size();
        int black=0,white=0;
        int mini = INT_MAX;
        while(j<n){
            if(j-i+1<k){
                if(blocks[j]=='W') white++;
                else black++;
                j++;
            }
            else if(j-i+1==k){
                if(blocks[j]=='W') white++;
                else black++;

                mini = min(mini,white);


                if(blocks[i]=='W') white--;
                else black--;

                j++;
                i++;
            }
        }
        return mini;
    }
};