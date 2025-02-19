class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int>pre(10,-1);
        for(int i=0;i<n;i++){
            int idx = s[i] - '0';
            pre[idx] = i;
        }

        for(int i=0;i<n;i++){
            char currChar = s[i];
            int currDigit = currChar-'0';

            for(int j=9;j>currDigit;j--){
                if(pre[j]>i){
                    swap(s[i],s[pre[j]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};