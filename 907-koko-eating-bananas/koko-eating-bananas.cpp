class Solution {
public:
    #define ll long long
    bool feasible(vector<int>& piles,int H,int threshold){
        int sum=0;
        int n = piles.size();
        ll hr = 0;
        for(int i=0;i<n;i++){
            if(piles[i]>=threshold){
                hr+=ceil(piles[i]/(double)threshold);
            }
            else{
                hr+=1;
            }

            if(hr>H) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 1e9;

        while(hi-lo>1){
            int mid = lo+(hi-lo)/2;

            if(feasible(piles,h,mid)) hi=mid;
            else lo=mid;
        }

        if(feasible(piles,h,lo)) return lo;
        if(feasible(piles,h,hi)) return hi;

        return -1;
    }
};