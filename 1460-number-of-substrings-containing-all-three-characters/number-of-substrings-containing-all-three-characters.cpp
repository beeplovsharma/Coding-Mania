class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        int cnt = 0;
        vector<int>hash(256,-1);
        int r = 0;
        while(r<n){
            hash[s[r]] = r;
            int mini = min(hash['a'],min(hash['b'],hash['c']));
            cnt = cnt + (1+mini);
            r++;
        }
        return cnt;

        // int n = s.size();
        // int cnt = 0;
        // for(int i=0;i<n;i++){
        //     set<char>st;
        //     for(int j=i;j<n;j++){
        //         st.insert(s[j]);

        //         // if(st.size()>=3) cnt++;
        //         if(st.size()>=3){
        //             cnt += (n-j);
        //             break;
        //         }
        //     }
        // }
        // return cnt;
    }
};