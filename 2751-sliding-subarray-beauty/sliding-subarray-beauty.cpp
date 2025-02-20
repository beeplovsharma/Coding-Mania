class Solution {
public:
    int findXth(map<int,int>&mp,int x){
        int cnt = 0;
        int xthElem = 0;
        for(auto it:mp){
            cnt += it.second;
            if(cnt>=x){
                if(it.first<0) xthElem = it.first;
                break;
            }
        }
        return xthElem;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int n = nums.size();
        int i=0,j=0;
        map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                int mini = findXth(mp,x);
                ans.push_back(mini);

                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};