class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int a = 0;
            for(int j=i;j<n;j++){
                a = a ^ arr[j];
                if(a==0){
                    cnt += (j-i);
                }
            }
        }
        return cnt;
    }
};