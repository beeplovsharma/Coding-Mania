class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";
        for(int i=1;i<=n+1;i++) ans += (i + '0');

        string res="";

        int i=0;
        while(i<n){
            int j=i;
            if(pattern[i]=='D'){
                while(j<n && pattern[j]=='D'){
                    j++;
                }
                string temp = ans.substr(i,j-i+1);
                reverse(temp.begin(),temp.end());
                res += temp;
                i=j+1;
            }
            else{
                res+=ans[i];
                i++;
            }
        }
        if(res.size()!=pattern.size()+1) res += ans[n];

        return res;
    }
};