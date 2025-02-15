class Solution {
public:
    bool check(string str,int n,int i,int sum){
        if(i==str.size()){
            return sum==n;
        }
        if(sum>n) return false;

        for(int j=i;j<str.size();j++){
            string sub = str.substr(i,j-i+1);
            int val = stoi(sub);
            if(check(str,n,j+1,sum+val)) return true;
        }

        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int sq = i*i;
            string stri = to_string(sq);
            if(check(stri,i,0,0)){
                ans += sq;
            }
        }
        return ans;
    }
};