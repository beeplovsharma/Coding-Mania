class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    vector<int>dp;
    int fun(string &s, int ind){
        if(ind==n) return 1;

        if(dp[ind]!=-1) return dp[ind];

        int count = 0;
        if(s[ind]!='0'){
            if(s[ind]=='*'){
            count = (count + 9 * 1LL * fun(s,ind+1) % MOD) % MOD;

            if(ind<n-1){
                char ch = s[ind+1];

                if(ch!='*'){
                    count = (count + fun(s,ind+2) % MOD) % MOD; // 1*
                    if('0'<=ch && ch<='6') count = (count + fun(s,ind+2) % MOD) % MOD; // 2*
                }else if(ch=='*'){
                    count = (count + 15 * 1LL * fun(s,ind+2) % MOD) % MOD;
                }
                }
            }
            else{
                count = (count + fun(s,ind+1) % MOD) % MOD;
                if(ind<n-1){
                    char ch = s[ind+1];
                    if(ch!='*' && stoi(s.substr(ind,2))>=10 && stoi(s.substr(ind,2))<=26){
                        count = (count + fun(s,ind+2) % MOD) % MOD;
                    }
                    else if(ch=='*' && s[ind]=='1'){
                        count = (count + 9 * 1LL * fun(s,ind+2) % MOD) % MOD;
                    }
                    else if(ch=='*' && s[ind]=='2'){
                        count = (count + 6 * 1LL * fun(s,ind+2) % MOD) % MOD;
                    }
                }
            }
        }

        return dp[ind] = count % MOD;
    }

    int numDecodings(string s) {
        n = s.size();
        dp.resize(n,-1);
        return fun(s,0)%MOD;
    }
};