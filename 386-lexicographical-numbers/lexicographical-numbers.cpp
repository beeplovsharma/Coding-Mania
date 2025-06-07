class Solution {
public:
    void solve(int x,int n,vector<int>&ans){
        if(x>n) return;

        ans.push_back(x);
        for(int i=0;i<10;i++){
            solve(10*x+i,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++) solve(i,n,ans);
        return ans;
    }
};