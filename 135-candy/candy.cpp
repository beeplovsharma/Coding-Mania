class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>profit(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                profit[i] = profit[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                profit[i]=max(profit[i], profit[i + 1] + 1);
            }
        }

        int candy = 0;
        for(auto x:profit) candy += x;

        return candy;
    }
};