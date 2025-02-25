class Solution {
public:
    bool feasible(vector<int>& bloomDay, int m, int k, int maxDay) {
        int n = bloomDay.size();
        int cnt = 0, bucket = 0;

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=maxDay){
                cnt++;

                if(cnt==k){
                    cnt=0;
                    bucket++;
                }
            }
            else{
                cnt=0;
            }

            if(bucket>=m) return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = 1;
        int hi = *max_element(bloomDay.begin(),bloomDay.end());

        while(hi-lo>1){
            int mid = lo+(hi-lo)/2;

            if(feasible(bloomDay,m,k,mid)) hi=mid;
            else lo=mid;
        }

        if(feasible(bloomDay,m,k,lo)) return lo;
        if(feasible(bloomDay,m,k,hi)) return hi;

        return -1;
    }
};