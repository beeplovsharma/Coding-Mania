class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>next(n+1,0),cur(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int notPick = 0 + next[prev_ind+1]; //must do index shifting of prev_ind
                int pick = 0;
                if(prev_ind == -1 || arr[ind]>arr[prev_ind]) 
                    pick = 1 + next[ind+1]; //must do index shifting of prev_ind
                
                cur[prev_ind+1] = max(pick,notPick);
            }
            next = cur;
        }

        return cur[-1+1];
    }
};