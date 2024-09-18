class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>minutes;
        for(auto x:timePoints){
            int h = stoi(x.substr(0,2));
            if(h==0) h = 24;
            int m = stoi(x.substr(3,2));

            minutes.push_back(h*60+m);
        }

        sort(minutes.begin(),minutes.end());

        int mini = INT_MAX;

        for(int i=1;i<minutes.size();i++){
            mini = min(mini,minutes[i]-minutes[i-1]);
        }

        return min(mini,(24*60 - minutes[minutes.size()-1])+minutes[0]);
    }
};