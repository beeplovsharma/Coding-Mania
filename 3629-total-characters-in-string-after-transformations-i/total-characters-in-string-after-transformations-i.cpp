class Solution {
public:
    const int M = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int>mp(26,0);

        for(auto &c:s) mp[c-'a']++;

        for(int count=0;count<t;count++){
            vector<int>temp(26,0);
            for(int i=0;i<26;i++){
                char ch = i+'a';
                int freq = mp[i];

                if(ch!='z'){
                    temp[ch-'a'+1] = (temp[ch-'a'+1] + freq)%M;
                }else{
                    temp[0]=(temp[0]+freq)%M;
                    temp[1]=(temp[1]+freq)%M;
                }

            }
            mp = move(temp);
        }

        int ans = 0;
        for(int i=0;i<26;i++){
            ans = (ans + mp[i])%M;
        }
        return ans;
    }
};