class Solution {
public:
    vector<vector<int>>dirs={{-1,0},{0,-1},{1,0},{0,1}};
    typedef pair<int,pair<int,int>> P;
    int minTimeToReach(vector<vector<int>>& move) {
        int n = move.size();
        int m = move[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        ans[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto node = pq.top();
            int curTime = node.first;
            int i = node.second.first;
            int j = node.second.second;
            pq.pop();

            if(i==n-1 && j==m-1) return curTime;

            for(auto &dir:dirs){
                int _i = i+dir[0];
                int _j = j+dir[1];
                int steps = _i + _j;

                if(_i>=0 && _i<n && _j>=0 && _j<m){
                    int wait = max(move[_i][_j]-curTime,0);
                    int newTime = curTime + wait + ((steps%2!=0)?1:2);

                    if(ans[_i][_j]>newTime){
                        ans[_i][_j]=newTime;
                        pq.push({newTime,{_i,_j}});
                    }
                }
            }
        }
        return -1;
    }
};