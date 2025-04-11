class Solution {
public:
    bool checkSymmetry(int n){
        string s = to_string(n);
        int i=0,j=s.size()-1;
        int leftSum = 0, rightSum=0;
        while(i<j){
            leftSum += s[i++]-'0';
            rightSum += s[j--]-'0';
        }

        return (leftSum!=0 && rightSum!=0 && leftSum==rightSum);
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i=low;i<=high;i++){
            int len = to_string(i).size();
            if (len % 2 == 0 && checkSymmetry(i)) cnt++;
        }
        return cnt;
    }
};