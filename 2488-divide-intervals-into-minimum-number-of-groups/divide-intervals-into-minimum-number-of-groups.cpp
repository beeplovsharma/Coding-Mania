class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>mp;

        for(auto x:intervals){
            int left = x[0];
            int right = x[1];

            mp[left]++;
            mp[right+1]--;
        }

        int maxi = 0;
        int sum = 0;
        for(auto x:mp){
            sum += x.second;
            maxi = max(maxi,sum);
        }

        return maxi;
    }
};