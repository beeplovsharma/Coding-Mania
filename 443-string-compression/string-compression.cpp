class Solution {
public:
    int compress(vector<char>& chars) {
        int ind = 0,i=0;
        char cur_ch = chars[0];
        int n = chars.size();

        while(i<n){
            int cur = 0;
            while(i<n && chars[i]==cur_ch){
                i++;
                cur++;
            }

            chars[ind] = cur_ch;
            ind++;
            if(cur>1){
                string cur_cnt = to_string(cur);
                for(auto ch:cur_cnt){
                    chars[ind++] = ch;
                }
            }
            if(i<n) cur_ch = chars[i];
        }

        return ind;
    }
};