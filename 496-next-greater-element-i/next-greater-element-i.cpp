class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n1=nums1.size(),n2=nums2.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n2;i++){
            int found = 0;
            for(int j=i+1;j<n2;j++){
                if(nums2[j]>nums2[i]){
                    mp[nums2[i]]=nums2[j];
                    found = 1;
                    break;
                }
            }
            if(found==0) mp[nums2[i]]=-1;
        }
        vector<int>ans;
        for(auto x:nums1){
            ans.push_back(mp[x]);
        }
        return ans;

        // int n1=nums1.size(),n2=nums2.size();
        // stack<int>st;
        // unordered_map<int,int>mp;
        // for(int i=n2-1;i>=0;i--){
        //     int x = nums2[i];
        //     if(st.empty()) mp[x]=-1;
        //     if(st.top()>x && !st.empty()) mp[x] = st.top();
        //     else{
        //         while(st.top()<=x && !st.empty()){
        //             st.pop();
        //         }
        //         if(!st.empty()) mp[x] = st.top();
        //         else mp[x] = -1;
        //     }
        //     st.push(x);
        // }
        // vector<int>ans;
        // for(auto x:nums1){
        //     ans.push_back(mp[x]);
        // }
        // return ans;
    }
};