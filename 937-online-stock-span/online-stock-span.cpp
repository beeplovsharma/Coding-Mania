class StockSpanner {
private: vector<int>v;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        int n = v.size();
        int cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(v[i]<=price) cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */