class Solution {
public:
    void fun(int start,int n,int k,vector<int>asf,vector<vector<int>>&ans){
        if(asf.size()==k){
            ans.push_back(asf);
            return;
        }

        for(int i=start;i<=n;i++){
            asf.push_back(i);
            fun(i+1,n,k,asf,ans);
            asf.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>asf;
        vector<vector<int>>ans;
        int start = 1;
        fun(start,n,k,asf,ans);
        return ans;
    }
};