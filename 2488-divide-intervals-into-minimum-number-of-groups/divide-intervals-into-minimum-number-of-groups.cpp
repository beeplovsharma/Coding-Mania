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

        //min no of group have to make = max no. of overlap
        int sum = 0;
        int maxi = 0;
        for(auto x:mp){
            sum += x.second;
            maxi = max(maxi,sum);
        }

        return maxi;
    }
};