class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> temp(n , 0);

        // Apply shift increments and decrements
        for (auto &shift : shifts) {
            int i = shift[0], j = shift[1], direction = shift[2] == 0 ? -1 : 1;

            temp[i] += direction;
            if (j + 1 < n) temp[j + 1] -= direction; 
        }

        // Calculate cumulative shift using prefix sum
        int cumulativeShift = 0;
        for (int i = 0; i < n; i++) {
            cumulativeShift += temp[i];
            int shift = (cumulativeShift % 26 + 26) % 26; // Normalize shifts
            s[i] = 'a' + (s[i] - 'a' + shift) % 26; // Apply the shift
        }

        return s;
    }
};