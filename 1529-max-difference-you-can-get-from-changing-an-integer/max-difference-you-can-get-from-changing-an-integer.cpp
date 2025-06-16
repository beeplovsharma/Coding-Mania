class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();
        
        string mini = "";
        string maxi = "";

        int i=0;
        while(i<n){
            char ch = s[i];
            if(ch!='9'){
                while(i<n){
                    if(s[i]==ch) maxi+='9';
                    else maxi+=s[i];

                    i++;
                }
            }else{
                maxi += ch;
            }
            i++;
        }

        i=0;
        if(s[0]!='1'){
            char ch = s[0];

            while(i<n){
                if(s[i]==ch){
                    mini += '1';
                }else{
                    mini+= s[i];
                }
                i++;
            }
        }
        else{
            while(i<n){
                char ch = s[i];
                if(ch!='1' && ch!='0'){
                    while(i<n){
                        if(s[i]==ch) mini+='0';
                        else mini+=s[i];
                        i++;
                    }
                }else{
                    mini+=ch;
                }
                i++;
            }
        }

        int a=stoi(maxi);
        int b=stoi(mini);

        cout<<a<<" "<<b;

        return a-b;
    }
};