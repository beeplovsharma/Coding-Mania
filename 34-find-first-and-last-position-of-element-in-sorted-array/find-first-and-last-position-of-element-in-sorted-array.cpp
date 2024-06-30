class Solution {
public:

int first(vector<int>&v,int x){
    int low = 0;
    int high = v.size()-1;
    int possibleInd = -1;
    while(low<=high){
        int mid= (low+high)/2;

        if(v[mid]==x){
            possibleInd = mid;
            high = mid-1;
        }

        else if(x>v[mid]) low = mid+1;
        else high = mid-1;
    }
    return possibleInd;
}
int last(vector < int > & v, int x) {
    int low = 0;
    int high = v.size()-1;
    int possibleInd = -1;
    while(low<=high){
        int mid= (low+high)/2;

        if(v[mid]==x){
            possibleInd = mid;
            low = mid+1;
        }

        else if(x>v[mid]) low = mid+1;
        else high = mid-1;
    }
    return possibleInd;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstInd = first(nums,target);
        int lastInd = last(nums,target);
        return {firstInd,lastInd};
    }
};