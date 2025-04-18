class Solution {
public:
    string fun(int n){
        if(n==1) return "1";

        string faith = fun(n-1);
        int i=0,j=1;
        string ans = "";
        while(j<faith.size()){
            if(faith[j]!=faith[j-1]){
                ans += to_string(j-i);
                ans += faith[j-1];

                i=j;
            }
            j++;
        }

        if(i<faith.size()){
            ans += to_string(j-i);
            ans += faith[j-1];
        }

        return ans;
    }
    string countAndSay(int n) {
        return fun(n);
    }
};