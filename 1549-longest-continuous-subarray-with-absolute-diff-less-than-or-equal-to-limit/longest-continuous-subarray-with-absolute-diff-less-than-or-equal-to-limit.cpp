class Solution {
public:
    typedef pair<int,int>P;
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0,j=0;
        int n = nums.size();

        priority_queue<P>mxHeap;
        priority_queue<P,vector<P>,greater<P>>mnHeap;

        int maxi = 0;

        while(j<n){
            mnHeap.push({nums[j],j});
            mxHeap.push({nums[j],j});

            while(i<=j && abs(mxHeap.top().first-mnHeap.top().first)>limit){
                int idx = min(mxHeap.top().second,mnHeap.top().second);
                i=idx+1;
                
                while(mxHeap.top().second<i) mxHeap.pop();
                while(mnHeap.top().second<i) mnHeap.pop();
            }
            
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};