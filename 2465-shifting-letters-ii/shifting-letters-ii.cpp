class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> temp(n , 0);
        for (auto &shift : shifts) {
            int i = shift[0], j = shift[1], direction = shift[2] == 0 ? -1 : 1;

            temp[i] += direction;
            if (j + 1 < n) temp[j + 1] -= direction; 
        }
        int cumshift = 0;
        for(int i=0;i<n;i++){
            cumshift += temp[i];
            int shift = (cumshift%26+26)%26;
            s[i] = 'a' + (s[i]-'a'+shift)%26;
        }
        return s;
    }
};