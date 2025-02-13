class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(begin(nums),end(nums));

        int cnt = 0;
        while(!pq.empty() && pq.top()<k){
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};