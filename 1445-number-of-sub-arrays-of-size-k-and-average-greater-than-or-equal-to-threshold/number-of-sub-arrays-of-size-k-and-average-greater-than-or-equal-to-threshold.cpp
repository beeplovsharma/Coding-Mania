class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i,sum=0;
        for(i = 0;i<k;i++) sum+= arr[i];
        int cnt = 0;
        if(sum/k >= threshold) cnt++;

        int l = 0 , r = i;
        int n = arr.size();
        while(r<n){
            sum = sum - arr[l];
            sum = sum + arr[r];

            if(sum/k >= threshold) cnt++;

            l++;
            r++;
        }
        return cnt;
    }
};