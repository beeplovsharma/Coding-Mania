class Solution {
public:
    void BFS(vector<int>& edges,vector<vector<int>>&dist,int start,int col,int n){
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(start);
        vis[start]=true;
        dist[start][col]=0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            int nextNode = edges[node];
            if (nextNode != -1 && !vis[nextNode]) {
                q.push(nextNode);
                vis[nextNode] = true;
                dist[nextNode][col] = dist[node][col] + 1;
            }

        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>>dist(n,vector<int>(2,-1));
        BFS(edges,dist,node1,0,n);
        BFS(edges,dist,node2,1,n);

        int ans = -1;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int a = dist[i][0];
            int b = dist[i][1];

            if(a!=-1 && b!=-1){
                int maxi = max(a,b);
                if(maxi<mini){
                    mini = maxi;
                    ans = i;
                }
            }
        }

        return ans;
    }
};