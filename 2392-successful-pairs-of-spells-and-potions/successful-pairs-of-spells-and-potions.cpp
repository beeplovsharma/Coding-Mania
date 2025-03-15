class Solution {
public:
    int fun(vector<int>& potions, long long success, int k){
        int m = potions.size();

        int lo=0,hi=m-1;
        while(hi-lo>1){
            int mid = lo + (hi-lo)/2;

            if(potions[mid]*1LL*k >= success) hi=mid;
            else lo=mid+1;
        }

        if(potions[lo]*1LL*k >= success) return lo;
        if(potions[hi]*1LL*k >= success) return hi;

        return m;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;

        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        
        for(int i=0;i<n;i++){
            int count = m - fun(potions,success,spells[i]);
            ans.push_back(count);
        }

        return ans;
    }
};