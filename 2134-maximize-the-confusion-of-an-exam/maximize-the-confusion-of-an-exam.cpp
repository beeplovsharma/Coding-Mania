class Solution {
public:

    int maxConsecutiveAnswers(string s, int k) {
        int i=0,j=0;
        int n = s.size();

        int cnt = INT_MIN;

        int flip = 0;
        // Check for F, if not, do this (T --> F (X))
        while(j<n){
            if(s[j]=='T'){
                flip++;
                s[j]='X';
            }

            while(flip > k){
                if(s[i]=='X') flip--;
                i++;
            }

            cnt = max(cnt,j-i+1);
            j++;
        }

        for(int i=0;i<n;i++){
            if(s[i]=='X') s[i] = 'T';
        }
        
        i=0,j=0;
        flip = 0;
        // Check for T, if not, do this (F --> T (X))
        while(j<n){
            if(s[j]=='F'){
                flip++;
                s[j]='X';
            }

            while(flip > k){
                if(s[i]=='X') flip--;
                i++;
            }

            cnt = max(cnt,j-i+1);
            j++;
        }

        return cnt;
    }
};