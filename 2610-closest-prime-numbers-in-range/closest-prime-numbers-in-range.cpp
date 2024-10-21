class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(left==right) return {-1,-1};
        vector<bool>prime(right+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=right;i++){
            if(prime[i]){
                for(int j=2*i;j<=right;j+=i){
                    prime[j]=false;
                }
            }
        }

        vector<int>p;
        for(int i=left;i<=right;i++){
            if(prime[i]){
                p.push_back(i);
            }
        }

        if(p.size()==1) return {-1,-1};

        int minDiff = INT_MAX;
        int x=-1,y=-1;
        for(int i=1;i<p.size();i++){
             int diff = p[i]-p[i-1];
             if(minDiff > diff){
                minDiff = diff;
                x = p[i-1];
                y = p[i];
             }
        }

        return {x,y};
    }
};