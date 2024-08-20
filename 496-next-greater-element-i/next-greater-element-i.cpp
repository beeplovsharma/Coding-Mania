class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m=nums2.size();
        map<int,int>mp;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(nums2[j]>nums2[i]){
                    mp[nums2[i]] = nums2[j];
                    break;
                }
            }
        }
        vector<int>nge;
        for(int i=0;i<n;i++){
            int el = mp[nums1[i]] == 0 ? -1 : mp[nums1[i]];
            nge.push_back(el);
        }
        return nge;
    }
};