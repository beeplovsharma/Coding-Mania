class Solution {
public:

    bool feasible(vector<int>& dist, double hour, int speed){
        double takenHour = 0;

        for(int i=0;i<dist.size();i++){
            takenHour += dist[i]/(double)speed;
            if(i!=dist.size()-1) takenHour = ceil(takenHour);
        }
        
        return hour>=takenHour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int lo = 1, hi = 1e7;

        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;
            if(feasible(dist,hour,mid)) hi=mid;
            else lo=mid;
        }

        if(feasible(dist,hour,lo)) return lo;
        if(feasible(dist,hour,hi)) return hi;

        return -1;

    }
};