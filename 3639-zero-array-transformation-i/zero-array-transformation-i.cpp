class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>diffArr(n,0);
        for(auto &it:queries){
            int l = it[0], r = it[1];
            diffArr[l] += -1;
            if(r+1<n) diffArr[r+1] += 1;
        }
        for(int i=1;i<diffArr.size();i++){
            diffArr[i] = diffArr[i]+diffArr[i-1];
        }

        for(int i=0;i<n;i++){
            if(abs(diffArr[i])>=nums[i]) nums[i]=0;
            else return false;
        }
        return true;
    }
};