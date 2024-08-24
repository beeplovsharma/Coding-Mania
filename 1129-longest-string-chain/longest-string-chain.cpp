class Solution {
public:
    bool compstr(string &a,string &b){
        if(a.size()!=b.size()+1) return false;

        int n = a.size(), m = b.size();
        int i=0;
        int j=0;

        while(i<n){
            if(j<m && a[i]==b[j]) i++,j++;
            else i++;
        }

        if(i==n && j==m) return true;
        
        return false;
    }
    
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(),words.end(),comp);

        vector<int>dp(n,1);
        int maxi = 1;
        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(compstr(words[ind],words[prev])){
                    dp[ind] = max(dp[ind],dp[prev]+1);
                }
            }
            maxi = max(maxi,dp[ind]);
        }
        return maxi;
    }
};