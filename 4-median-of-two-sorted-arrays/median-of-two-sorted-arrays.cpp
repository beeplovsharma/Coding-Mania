class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int n = nums1.size();
        int right = 0;
        int m = nums2.size();
        vector<int>temp;

        while(left<n && right<m){
            if(nums1[left]<nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }
            else{
                temp.push_back(nums2[right]);
                right++;
            }
        }

        while(left<n){
            temp.push_back(nums1[left]);
            left++;
        }
        while(right<m){
            temp.push_back(nums2[right]);
            right++;
        }

        int size = temp.size();
        double median=0;
        if(size&1){
            median = temp[(size)/2];
        }
        else{
            median = (double)(temp[size/2]+temp[size/2-1])/2;
        }
        return median;
    }
};