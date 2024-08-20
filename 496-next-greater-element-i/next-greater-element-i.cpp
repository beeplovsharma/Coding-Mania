class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m=nums2.size();
        map<int,int>mp;
        stack<int>st;
        for(int i=m-1;i>=0;i--){
            int cur_elem = nums2[i];
            while(!st.empty() && st.top()<=cur_elem) st.pop();
            if(st.empty()) mp[cur_elem] = -1;
            else{
                mp[cur_elem] = st.top();
            } 
            st.push(cur_elem);
        }
        vector<int>nge;
        for(int i=0;i<n;i++){
            nge.push_back(mp[nums1[i]]);
        }
        return nge;
    }
};