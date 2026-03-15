class Solution {
public:
    typedef pair<int,int>P;
    int MST(int V, vector<P>adj[]) {
        priority_queue<P,vector<P>,greater<P>>pq; //{wt,node}
        pq.push({0,0});
        
        int sum = 0;
        vector<bool>isMST(V,false);
        
        while(!pq.empty()){
            auto [wt,node] = pq.top();
            pq.pop();
            
            if(isMST[node]) continue;
            
            sum += wt;
            isMST[node] = true;
            
            for(auto [v,w]:adj[node]){
                if(!isMST[v]){
                    pq.push({w,v});
                }
            }
        }
        
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& nums) {
        int V = nums.size();
        vector<P>adj[V];

        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1 = nums[i][0];
                int y1 = nums[i][1];
                
                int x2 = nums[j][0];
                int y2 = nums[j][1];

                int mhd = abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,mhd});
                adj[j].push_back({i,mhd});
            }
        }

        return MST(V,adj);
    }
};