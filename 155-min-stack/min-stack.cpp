class MinStack {
public:
    vector<int>v;
    map<int,int>mp; 
    MinStack() {
    }
    
    void push(int val) {
        v.push_back(val);
        mp[val]++;
    }
    
    void pop() {
        int last = v.back();
        v.pop_back();
        mp[last]--;
        if(mp[last]==0) mp.erase(last);
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        auto first = mp.begin();
        return first->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */