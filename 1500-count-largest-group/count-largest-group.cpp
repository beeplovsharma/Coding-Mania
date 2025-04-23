class Solution {
public:
    int sumOfDig(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n=n/10;
        }
        cout<<ans<<" ";
        return ans;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
        for(int i=1;i<=n;i++){
            int x = sumOfDig(i);
            mp[x]++;
            maxi = max(maxi,mp[x]);
        }
        int cnt = 0;
        for(auto x:mp){
            if(x.second==maxi) cnt++;
        }
        return cnt;
    }
};