class Solution {
public:
    int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0,even = 1;
        int currSum;
        long long ans=0;
        for(int i=0;i<arr.size();i++){
           currSum += arr[i];
           if(currSum % 2 == 0)
             {
                 even++;
                 ans += odd;
             }
            else{
                odd++;
                ans += even;
            }
        }
        return ans%MOD;
    }
};