class Solution {
public:
    vector<int>parent;

    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a,int b){
        int pa = find(a);
        int pb = find(b);

        if(pa<pb){
            parent[pb] = pa;
        }else{
            parent[pa] = pb;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i]=i;
        int n = s1.size();
        for(int i=0;i<n;i++){
            int a = s1[i]-'a';
            int b = s2[i]-'a';
            Union(a,b);
        }

        int m = baseStr.size();
        string ans="";

        for(int i=0;i<m;i++){
            int x = baseStr[i]-'a';
            char ch = find(x)+'a';
            ans+=ch;
        }

        return ans;
    }
};