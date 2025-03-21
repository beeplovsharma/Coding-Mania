class Solution {
public:
//boht hard ques
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        sort(queries.begin(),queries.end());

        int j=0;
        priority_queue<int>candidate;
        priority_queue<int,vector<int>,greater<int>>chosen;
        int ans = 0;
        for(int i=0;i<n;i++){
            while(j<q && queries[j][0]==i){
                candidate.push(queries[j][1]);
                j++;
            }

            nums[i]-=chosen.size();

            while(nums[i]>0 && !candidate.empty() && candidate.top()>=i){
                ans++;
                chosen.push(candidate.top());
                candidate.pop();
                nums[i]--;
            }

            if(nums[i]>0) return -1;

            while(!chosen.empty() && chosen.top()==i){
                chosen.pop();
            }
        }

        return queries.size()-ans;
    }
};