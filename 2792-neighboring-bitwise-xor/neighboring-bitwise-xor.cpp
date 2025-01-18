class Solution {
public:
    bool checkXOR(vector<int>& v, vector<int>& derived) {
    int n = v.size();
    if (n == 0 || derived.size() != n) return false;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            if (v[i] ^ v[0] != derived[i]) return false;
        } else {
            if ((v[i] ^ v[i + 1]) != derived[i]) return false;
        }
    }
    return true;
}

    void makeXOR(vector<int>&v,vector<int>derived,int s){
        v.push_back(s);
        for(int i=0;i<derived.size()-1;i++){
            int x = v[i];
            int y = derived[i];
            v.push_back(x^y);
        }
    }
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int>v;

        makeXOR(v,derived,0);
        if(checkXOR(v,derived)) return true;

        makeXOR(v,derived,1);
        if(checkXOR(v,derived)) return true;
        
        return false;
    }
};