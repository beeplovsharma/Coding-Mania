class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    int maxVowels(string s, int k) {
        int n = s.size();

        int vow = 0;
        int i=0,j=0;
        int maxi = INT_MIN;
        while(j<n){
            if(isVowel(s[j])) vow++;

            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                maxi = max(vow,maxi);
                if(isVowel(s[i])) vow--;
                i++;
                j++;
            }
        }

        return maxi;
    }
};