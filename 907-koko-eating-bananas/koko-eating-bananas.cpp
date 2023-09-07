class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

    int n = piles.size();
    int low = 1,high=*max_element(piles.begin(),piles.end());
    int mid = (low+mid)/2;
    int ans = -1;
    while(low<=high){
        mid = low+(high-low)/2;
        double hrs = 0;
        for(int i=0;i<n;i++){
            hrs += ceil(double(piles[i])/mid);
        }

        if(hrs<=h){
            ans = mid;
            high = mid-1;
        }

        else{
            low = mid+1;
        }
    }
    return ans;

    }
};