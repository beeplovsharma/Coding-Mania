class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int>pre(n,0);
        pre[n-1] = n-1;

        for(int i=n-2;i>=0;i--){
            if(s[i]<=s[pre[i+1]]) pre[i] = pre[i+1];
            else pre[i] = i;
        }


        for(int i=0;i<n;i++){
            if(s[i]==s[pre[i]]) continue;

            swap(s[i],s[pre[i]]);
            break;
        }

        return stoi(s);
    }
};