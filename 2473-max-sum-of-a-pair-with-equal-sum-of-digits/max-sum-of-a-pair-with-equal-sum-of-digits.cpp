class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n!=0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>sumHash(n,0);
        for(int i=0;i<n;i++){
            sumHash[i] = digitSum(nums[i]);
        }

        unordered_map<int,int>mp;
        int maxi = -1;
        for(int i=0;i<n;i++){
            if(mp.find(sumHash[i])!=mp.end()){
                int idx = mp[sumHash[i]];
                maxi = max(maxi,nums[idx]+nums[i]);

                if(nums[i]>nums[idx]) mp[sumHash[i]]=i;
            }
            else mp[sumHash[i]] = i;
        }

        return maxi;
    }
};