class NumberContainers {
public:
    unordered_map<int,int>idxToNum;
    unordered_map<int,set<int>>numToIdx;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idxToNum.find(index)!=idxToNum.end()){
            int prev_num = idxToNum[index];
            numToIdx[prev_num].erase(index);
            if(numToIdx[prev_num].empty()) numToIdx.erase(prev_num);
        }
        idxToNum[index]=number;
        numToIdx[number].insert(index);
    }
    
    int find(int number) {
        if(numToIdx.find(number)==numToIdx.end()) return -1;

        return *numToIdx[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */