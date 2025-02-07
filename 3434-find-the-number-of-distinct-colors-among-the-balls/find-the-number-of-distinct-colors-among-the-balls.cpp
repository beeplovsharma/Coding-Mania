class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>ans;
        map<int,int>column;
        unordered_map<int,int>m;
        int diff = 0;
        for(auto x:queries){
            if(column.find(x[0])==column.end()){
                column[x[0]]=x[1];
                if(m.find(x[1])==m.end()) diff++;
                m[x[1]]++; 
            }
            else{
                m[column[x[0]]]--;
                if(m[column[x[0]]]==0){
                    m.erase(column[x[0]]);
                    diff--;
                }
                column[x[0]]=x[1];
                if(m.find(x[1])==m.end()) diff++;

                m[x[1]]++;
            }
            ans.push_back(diff);
        }
        return ans;
    }
};