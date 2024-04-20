class Solution {
public:
    int characterReplacement(string s, int k) {

        // OPTIMAL
        int n = s.size();
        int l=0,r = 0;
        vector<int>hash(26,0);
        int maxFreq = 0, maxLen = 0;
        while(r<n){
            hash[s[r]-'A']++;

            maxFreq = max(maxFreq,hash[s[r]-'A']);

            if((r-l+1)-maxFreq > k){
                hash[s[l]-'A']--;
                l++;
            }

            if((r-l+1)-maxFreq <= k) maxLen = max(maxLen,r-l+1);

            r++;
        }
        return maxLen;

        // BETTER
        // int n = s.size();
        // int l=0,r = 0;
        // vector<int>hash(26,0);
        // int maxFreq = 0, maxLen = 0;
        // while(r<n){
        //     hash[s[r]-'A']++;

        //     maxFreq = max(maxFreq,hash[s[r]-'A']);

        //     while((r-l+1)-maxFreq > k){
        //         hash[s[l]-'A']--;
        //         l++;

        //         maxFreq = 0;

        //         for(int i=0;i<26;i++) maxFreq = max(maxFreq,hash[i]);
        //     }

        //     if((r-l+1)-maxFreq <= k) maxLen = max(maxLen,r-l+1);

        //     r++;
        // }
        // return maxLen;

        // int n = s.size();
        // int maxLen = 0;
        // for(int i=0;i<n;i++){
        //     vector<int>hash(26,0);
        //     int maxFreq = 0;
        //     for(int j=i;j<n;j++){
        //         hash[s[j]-'A']++;

        //         maxFreq = max(maxFreq,hash[s[j]-'A']);
        //         int changes = (j-i+1) - maxFreq;

        //         if(changes <= k){
        //             maxLen = max(maxLen,j-i+1);
        //         } 
        //         else break;
        //     }
        // }
        // return maxLen;
    }
};