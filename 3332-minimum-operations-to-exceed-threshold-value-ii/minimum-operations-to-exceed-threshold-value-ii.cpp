class Solution {
public:
    #define ll long long
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq(begin(nums),end(nums)); //Heapify - log(n)

        int op = 0;
        while(!pq.empty() && pq.top()<k){
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();

            pq.push(x*2+y);
            op++;
        }

        return op;

    }
};