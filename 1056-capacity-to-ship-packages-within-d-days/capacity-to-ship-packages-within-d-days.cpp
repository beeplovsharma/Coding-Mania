class Solution {
public:
    bool predicate(vector<int>& weights,int capacity,int D){
        int totWeight = 0;
        int days = 1;
        for(auto weight:weights){
            totWeight+=weight;

            if(totWeight>capacity){
                days++;
                totWeight = weight;

                if(days>D) return false;
            }
        }
        return true;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(),weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);

        while(hi-lo>1){
            int mid = (lo+hi)/2;

            if(predicate(weights,mid,days)) hi=mid;
            else lo=mid+1;
        }

        if(predicate(weights,lo,days)) return lo;
        if(predicate(weights,hi,days)) return hi;

        return -1;
    }
};