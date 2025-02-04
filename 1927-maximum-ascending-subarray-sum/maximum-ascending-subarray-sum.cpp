class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {
        int maxi = arr[0];
        int n = arr.size();
        int sum = arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                sum+=arr[i];
                maxi=max(maxi,sum);
            }
            else{
                sum=arr[i];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};