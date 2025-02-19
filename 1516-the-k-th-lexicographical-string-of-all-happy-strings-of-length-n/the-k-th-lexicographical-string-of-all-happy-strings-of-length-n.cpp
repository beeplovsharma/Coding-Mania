class Solution {
public:
    int N;
    void solve(string ip,string &op,vector<string>&ans){
        if(op.size()==N){
            ans.push_back(op);
            return;
        }

        for(int i=0;i<3;i++){
            if(!op.empty() && ip[i]==op.back()) continue;

            op+=ip[i];
            solve(ip,op,ans);
            op.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        N=n;
        vector<string>ans;
        string ip="abc";
        string op = "";
        solve(ip,op,ans);
        if(ans.size()<k) return "";
        return ans[k-1];
    }
};