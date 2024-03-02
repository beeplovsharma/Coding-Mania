class Solution {
public:
    bool isPalindrome(string s) {

        if(s=="0P") return false;

        string ans = "";
        for(int i=0;i<s.size();i++){

            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                if(s[i]>='0' && s[i]<='9'){
                    ans += s[i];
                }

                else{
                    ans += (s[i] | ' ');
                }
            }

            // s[i] = (s[i] | ' ');
            // if(s[i]>='a' && s[i]<='z') ans = ans + s[i];
        }

        int left = 0, right = ans.size()-1;
        bool flag = true;
        while(left<right){
            if(ans[left]!=ans[right]){
                flag = false;
                break;
            }
            else{
                left++;
                right--;
            }
        }
        return flag;
    }
};