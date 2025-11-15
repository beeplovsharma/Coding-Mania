class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>a,const pair<int,int>b)const{
            if(a.second!=b.second) return a.second > b.second;
            return a.first < b.first;
        }
    };
    typedef long long ll;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();

        set<pair<ll,ll>,cmp>st;
        unordered_map<ll,ll>mp;
        vector<long long>ans(n);


        for(int i=0;i<n;i++){
            ll num = nums[i];
            ll fre = freq[i];
            ll oldFreq = mp[num];
            ll newFreq = fre+oldFreq;
            mp[num]=newFreq;
            
            if(oldFreq>0) st.erase({num,oldFreq});

            st.insert({num,newFreq});
            ans[i] = st.begin()->second;
        }

        return ans;
    }
};