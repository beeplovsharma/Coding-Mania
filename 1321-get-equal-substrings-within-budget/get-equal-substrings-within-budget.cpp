class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0;
        int n = s.size();
        int maxi = INT_MIN;
        int sum=0;

        while(j<n){
            sum += abs(s[j]-t[j]);
            while(sum>maxCost){
                sum -= abs(s[i]-t[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;

    }
};