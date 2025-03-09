class Solution {
public:
    typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>>v(n);

        for(int i=0;i<n;i++){
            v[i] = {nums1[i],i,nums2[i]}; //nums1 , ind , nums2
        }

        sort(v.begin(),v.end());

        vector<ll>ans(n,0);
        ll sum = 0;
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<n;i++){
            int n1 = v[i][0];
            int ind = v[i][1];
            int n2 = v[i][2];

            if(i>0 && v[i][0]==v[i-1][0]){
                ans[ind] = ans[v[i-1][1]];
            }
            else{
                ans[ind]=sum;
            }

            pq.push(n2);
            sum+=n2;

            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};