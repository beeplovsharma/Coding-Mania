class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int mini = INT_MAX;

        int i=0;
        map<int,int>mp;
        for(int j=0;j<n;j++){
            mp[cards[j]]++;

            while(i<=j && mp.size()<j-i+1){
                mini = min(mini,j-i+1);
                mp[cards[i]]--;
                if(mp[cards[i]]==0) mp.erase(cards[i]);
                i++;
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};