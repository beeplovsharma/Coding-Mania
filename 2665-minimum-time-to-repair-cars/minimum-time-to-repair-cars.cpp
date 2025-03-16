class Solution {
public:
    typedef long long ll;

    ll repCars(int rank,ll time){
        ll ans = time/rank;
        return sqrt(ans);
    }
    bool feasible(vector<int>& ranks, int cars, ll time){
        int n = ranks.size();

        for(int i=0;i<n;i++){
            cars-=repCars(ranks[i],time);

            if(cars<=0) return true;
        }

        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int maxRank=*max_element(ranks.begin(),ranks.end());

        ll lo = 1;
        ll hi = maxRank*1LL*cars*cars;

        while(hi-lo>1){
            ll mid = lo + (hi-lo)/2;

            if(feasible(ranks,cars,mid)) hi = mid;
            else lo = mid;
        }

        if(feasible(ranks,cars,lo)) return lo;
        if(feasible(ranks,cars,hi)) return hi;

        return -1;
    }
};