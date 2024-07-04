class Solution {
public:
    void makePrev(vector<int>& heights,vector<int>& prev){
        stack<int>st;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int x = heights[i];
            if(!st.empty() && heights[st.top()]<x){
                prev[i] = st.top();
            }
            while(!st.empty() && heights[st.top()]>=x) st.pop();
            int res = st.empty() ? -1 : st.top();
            prev[i] = res;
            st.push(i);
        }
    }
    void makeNext(vector<int>& heights,vector<int>& next){
        stack<int>st;
        int n = heights.size();
        for(int i=n-1;i>=0;i--){
            int x = heights[i];
            if(!st.empty() && heights[st.top()]<x){
                next[i] = st.top();
            }
            while(!st.empty() && heights[st.top()]>=x) st.pop();
            int res = st.empty() ? n : st.top();
            next[i] = res;
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prev(n,-1);
        vector<int>next(n,-1);

        makePrev(heights,prev);
        makeNext(heights,next);

        int maxHt = INT_MIN;
        for(int i=0;i<n;i++){
            int tot = next[i]-prev[i]-1;
            int curHt = tot * heights[i];

            maxHt = max(maxHt,curHt);
        }
        return maxHt;
    }
};