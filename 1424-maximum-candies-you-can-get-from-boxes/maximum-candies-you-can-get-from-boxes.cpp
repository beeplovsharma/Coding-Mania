class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<containedBoxes[i].size();j++){
                adj[i].push_back(containedBoxes[i][j]);
            }
        }
        
        queue<int>q;
        vector<bool>vis(n,false);
        set<int>lockedBox;
        for(auto &x:initialBoxes){
            if(status[x]==1){
                q.push(x);
            }else{
                lockedBox.insert(x);
            }
        }
        int ans = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans+=candies[node];
            if(keys[node].size()!=0){
                for(auto key:keys[node]){
                    status[key]=1;
                    if(lockedBox.find(key)!=lockedBox.end()){
                        q.push(key);
                        lockedBox.erase(key);
                    }
                }
            }

            for(auto &v:adj[node]){
                if(!vis[v]){
                    if(status[v]==1){
                        q.push(v);
                        vis[v]=true;
                    }else{
                        lockedBox.insert(v);
                    }
                }
            }
        }
        return ans;
    }
};