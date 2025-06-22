class Solution {
public:
    bool checkAndDelete(string &senate,int idx,char ch){
        bool roundTrip = false;
        while(true){
            if(idx==0) roundTrip=true;

            if(senate[idx]==ch){
                senate.erase(senate.begin()+idx);
                break;
            }

            idx = (idx+1)%(senate.size());
        }
        return roundTrip;
    }
    string predictPartyVictory(string senate) {
        int radiant_count = count(senate.begin(),senate.end(),'R');
        int dire_count = senate.size()-radiant_count;

        int idx = 0;
        while(radiant_count>0 && dire_count>0){
            if(senate[idx]=='D'){
                bool leftDeleted = checkAndDelete(senate,(idx+1)%senate.size(),'R');
                radiant_count--;
                if(leftDeleted) idx--;
            }else{
                bool leftDeleted = checkAndDelete(senate,(idx+1)%senate.size(),'D');
                dire_count--;
                if(leftDeleted) idx--;
            }

            idx = (idx+1)%(senate.size());
        }

        return radiant_count==0 ? "Dire" : "Radiant";
    }
};