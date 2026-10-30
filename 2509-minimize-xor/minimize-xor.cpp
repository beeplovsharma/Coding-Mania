class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;
        int set_bit = 0;
        for(int i=31;i>=0;i--){
            if((num2>>i)&1) set_bit++;
        }

        for(int i=31;i>=0;i--){
            if((num1>>i)&1 && set_bit){
                set_bit--;
                x |= (1<<i);
            }
        }

        int i=0;
        while(set_bit){
            if((1<<i)&x) i++;
            else{
                x |= (1<<i);
                set_bit--;
            }
        }

        return x;
    }
};