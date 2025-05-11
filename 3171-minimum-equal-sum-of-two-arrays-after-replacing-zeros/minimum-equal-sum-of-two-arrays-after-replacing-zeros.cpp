class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0, zero2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        long long s1 = 0, s2=0;
        for(int i=0;i<n1;i++){
            s1 += nums1[i];
            if(nums1[i]==0){
                 s1+=1;
                 zero1++;
            }
        }
        for(int i=0;i<n2;i++){
            s2 += nums2[i];
            if(nums2[i]==0){
                s2+=1;
                zero2++;
            }
        }

        cout<<s1<<" "<<s2;

        if(s1==s2) return s1;

        if(s1<s2){
            if(zero1>0) return s2;
        }else{
            if(zero2>0) return s1;
        }

        return -1;
    }
};