class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int n = nums1.size(), m = nums2.size();
        vector<int>merged;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]) merged.push_back(nums1[i++]);
            else if(nums1[i]>nums2[j]) merged.push_back(nums2[j++]);
            else if(nums1[i]==nums2[j]){
                merged.push_back(nums1[i++]);
                merged.push_back(nums2[j++]);
            }
        }

        while(i<n){
            merged.push_back(nums1[i++]);
        }
        while(j<m){
            merged.push_back(nums2[j++]);
        }

        int size = merged.size();
        if(size%2==0){
            return (double(merged[size/2]) + double(merged[size/2-1]))/2.0;
        }
        
        return merged[size/2];
    }
};