class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>temp;

        bool isNumber = true;
        for(auto ch:expression){
            if(ch=='+' || ch=='-' || ch=='*'){
                isNumber=false;
                break;
            }
        }

        if(isNumber){
            temp.push_back(stoi(expression));
            return temp;
        }

        vector<int>ans;
        
        for(int i=0;i<expression.size();i++){
            char ch = expression[i];

            if(ch=='+' || ch=='-' || ch=='*'){
                vector<int>left = diffWaysToCompute(expression.substr(0,i));
                vector<int>right = diffWaysToCompute(expression.substr(i+1));

                for(auto l:left){
                    for(auto r:right){
                        if(ch=='+'){
                            ans.push_back(l+r);
                        }
                        else if(ch=='-'){
                            ans.push_back(l-r);
                        }
                        else{
                            ans.push_back(l*r);
                        }
                    }
                }
            }
        }
        return ans;
    }
};