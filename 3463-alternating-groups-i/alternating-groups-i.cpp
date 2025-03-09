class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);

        int i=0,j=0;
        int n = colors.size();
        int cnt = 0;
        while(j<n){
            if(j-i+1<3){
                j++;
            }
            else{
                bool flag = true;
                for(int k=i+1;k<=j;k++){
                    if(colors[k]^colors[k-1]==0){
                        flag = false;
                    }
                }
                if(flag)cnt++;

                j++;
                i++;
            }
        }

        return cnt;
    }
};