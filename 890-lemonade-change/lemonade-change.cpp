class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0, ten = 0, twenty = 0;
        for(int i=0;i<n;i++){
            if(bills[i]==5) five++;

            else if(bills[i]==10){
                if(five){
                    five--;
                    ten++;
                }
                else return false;
            }

            else {
                if(five && ten){
                twenty++;
                five--;
                ten--;
               }
               else if(five>=3){
                twenty++;
                five = five-3;
               }
               else return false;
            }
        }

        return true;
    }
};