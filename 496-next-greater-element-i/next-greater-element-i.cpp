class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // int n1=nums1.size(),n2=nums2.size();
        // unordered_map<int,int>mp;
        // for(int i=0;i<n2;i++){
        //     int found = 0;
        //     for(int j=i+1;j<n2;j++){
        //         if(nums2[j]>nums2[i]){
        //             mp[nums2[i]]=nums2[j];
        //             found = 1;
        //             break;
        //         }
        //     }
        //     if(found==0) mp[nums2[i]]=-1;
        // }
        // vector<int>ans;
        // for(auto x:nums1){
        //     ans.push_back(mp[x]);
        // }
        // return ans;

        unordered_map<int,int>mp;
        stack<int>st;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            int ele = nums2[i];
            while(!st.empty() && st.top()<=ele){
                st.pop();
            }
            int res = (st.empty()) ? -1 : st.top();
            mp[ele] = res;
            st.push(ele);
        }
        vector<int>ans;
        for(auto x:nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};