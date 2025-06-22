class Solution {
public:
    void checkAndDelete(string &senate,int idx,char ch,vector<int>&deleted){
        while(true){

            if(senate[idx]==ch && !deleted[idx]){
                deleted[idx]=true;
                return;
            }

            idx = (idx+1)%(senate.size());
        }
    }
    string predictPartyVictory(string senate) {
        int radiant_count = count(senate.begin(),senate.end(),'R');
        int dire_count = senate.size()-radiant_count;
        vector<int>deleted(senate.size(),false);
        int idx = 0;
        while(radiant_count>0 && dire_count>0){
            if(senate[idx]=='D' && !deleted[idx]){
                checkAndDelete(senate,(idx+1)%senate.size(),'R',deleted);
                radiant_count--;
            }else if(senate[idx]=='R' && !deleted[idx]){
                checkAndDelete(senate,(idx+1)%senate.size(),'D',deleted);
                dire_count--;
            }

            idx = (idx+1)%(senate.size());
        }

        return radiant_count==0 ? "Dire" : "Radiant";
    }
};