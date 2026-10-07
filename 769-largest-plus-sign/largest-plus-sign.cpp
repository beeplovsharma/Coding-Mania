class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>ans(n, vector<int>(n,1e9));

        for(auto &x:mines){
            int i = x[0];
            int j = x[1];

            ans[i][j] = 0;
        }

        //left-right
        for(int i=0;i<n;i++){
            int left = 0;
            for(int j=0;j<n;j++){
                left++;

                if(ans[i][j]==0) left = 0;
                ans[i][j] = min(ans[i][j],left);
            }

            int right = 0;
            for(int j=n-1;j>=0;j--){
                right++;

                if(ans[i][j]==0) right = 0;
                ans[i][j] = min(ans[i][j],right);
            }
        }

        //top-bottom
        for(int i=0;i<n;i++){
            int left = 0;
            for(int j=0;j<n;j++){
                left++;

                if(ans[j][i]==0) left = 0;
                ans[j][i] = min(ans[j][i],left);
            }

            int right = 0;
            for(int j=n-1;j>=0;j--){
                right++;

                if(ans[j][i]==0) right = 0;
                ans[j][i] = min(ans[j][i],right);
            }
        }
        
        int maxx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxx = max(maxx,ans[i][j]);
            }
        }

        return maxx;
    }
};