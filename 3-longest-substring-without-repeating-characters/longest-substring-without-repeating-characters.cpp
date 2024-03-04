class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int head=0,tail=0,ans=0;
        int n = s.size();
        unordered_map<char,int>mp;
        for(head=0;head<n;head++){
            mp[s[head]]++;
            while(mp[s[head]]>1){
                ans=max(ans,head-tail);
                mp[s[tail]]--;
                tail++;
            }
        }
        return max(ans,head-tail);

        // int ans = 0;
        // for(int i=0;i<s.size();i++){
        //     vector<int>hash(256);
        //     for(int j=i;j<s.size();j++){
        //         if(hash[s[j]]){
        //             break;
        //         }
                
        //         else{
        //             ans = max(ans,j-i+1);
        //             hash[s[j]]=1;
        //         }
        //     }
        // }
        // return ans;
    }
};