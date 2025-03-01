class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }

        vector<int>final;
        
        for(int i=0;i<n;i++){
            if(nums[i]!=0) final.push_back(nums[i]);
            else cnt++;
        }

        int i=0;
        while(i<cnt){
            final.push_back(0);
            i++;
        }
        return final;
    }
};