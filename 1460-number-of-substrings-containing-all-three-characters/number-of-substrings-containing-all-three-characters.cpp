class Solution {
public:
    int solve(string s,int k){
        int l = 0 , r = 0;
        int n = s.size();
        int cnt = 0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;

            while(l<=r && mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }

            if(mp.size()<=k) cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubstrings(string s) {

        int x = solve(s,3);
        int y = solve(s,2);
        return (x-y);

        // int n = s.size();
        // int cnt = 0;
        // vector<int>hash(3,-1);
        // int r = 0;
        // while(r<n){
        //     hash[s[r]-'a'] = r;
        //     int mini = min(hash[0],min(hash[1],hash[2]));
        //     cnt = cnt + (1+mini);
        //     r++;
        // }
        // return cnt;

        // Brute
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