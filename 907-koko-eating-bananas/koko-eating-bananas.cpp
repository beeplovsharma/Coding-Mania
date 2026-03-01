class Solution {
public:
    bool feasible(vector<int>& piles,int speed, int h){
        int hours = 0;
        for(int i=0;i<piles.size();i++){
            int req = ceil(piles[i]/(1.0 * speed));
            hours += req;
        }
        return hours<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(feasible(piles,mid,h)) hi = mid;
            else lo = mid+1;
        }

        if(feasible(piles,lo,h)) return lo;
        if(feasible(piles,hi,h)) return hi;

        return -1;
    }
};