class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi = 1;
        int last_ind = 0;
        sort(arr.begin(),arr.end());

        for(int ind = 0;ind<n;ind++){
            hash[ind] = ind;
            for(int prev=0;prev<ind;prev++){
                if(arr[ind]%arr[prev]==0 && dp[ind] < dp[prev]+1){
                    dp[ind] = dp[prev]+1;
                    hash[ind] = prev;
                }
            }
            if(maxi<dp[ind]){
                maxi = dp[ind];
                last_ind = ind;
            }
        }

        vector<int>temp;
        temp.push_back(arr[last_ind]);
        while(hash[last_ind]!=last_ind){
            last_ind = hash[last_ind];
            temp.push_back(arr[last_ind]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};