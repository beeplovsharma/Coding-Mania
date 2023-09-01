class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int maxi = 1;
        for(int i=0;i<n;i++){
            vector<int>visited(256);
            visited[s[i]]++;
            for(int j=i+1;j<n;j++){
                if(visited[s[j]]){
                    maxi = max(j-i+1,maxi);
                    visited[s[j]]++;
                }

                else{
                    break;
                }
            }
        }
        return maxi;
    }
};