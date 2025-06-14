class Solution {
public:
    void fun(string str,int open,int close,vector<string>&ans){
        if(open==0 && close==0) ans.push_back(str);

        if(open>0){
            fun(str+"(",open-1,close,ans);
        }
        if(close>open){
            fun(str+")",open,close-1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str="";
        fun(str,n,n,ans);
        return ans;
    }
};