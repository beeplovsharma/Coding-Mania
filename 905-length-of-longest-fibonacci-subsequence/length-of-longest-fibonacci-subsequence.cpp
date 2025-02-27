class Solution {
public:

    int solve(vector<int>& nums,unordered_set<int>&st,int x,int y){
        int n = nums.size();
        int next = x+y;
        if(st.find(next)==st.end()) return 0;

        return 1+solve(nums,st,y,next);
        
    }
    
    int lenLongestFibSubseq(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        unordered_set<int>st(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int ans = 2+solve(nums,st,nums[i],nums[j]);
                maxi = max(maxi,ans);
            }
        }
        return maxi > 2 ? maxi : 0;
    }
};