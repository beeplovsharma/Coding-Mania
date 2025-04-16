class Solution {
public:
    #define ll long long
    long long countGood(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int p = 0;
        ll ans = 0;
        unordered_map<int, pair<int, int>> mp; //[num, {cnt, pairs}]

        while (j < n) {
            mp[nums[j]].first++;  // increase frequency

            // update pair count for nums[j]
            int cur_cnt = mp[nums[j]].first;
            int new_pairs = cur_cnt * (cur_cnt - 1) / 2;
            p = p - mp[nums[j]].second + new_pairs;
            mp[nums[j]].second = new_pairs;

            // shrink window while valid
            while (p >= k) {
                ans += (n - j);

                // update pair count for nums[i] before removing
                int cur_cnt_i = mp[nums[i]].first;
                int old_pairs_i = mp[nums[i]].second;

                mp[nums[i]].first--;  // decrease frequency
                int new_cnt_i = mp[nums[i]].first;
                int new_pairs_i = new_cnt_i * (new_cnt_i - 1) / 2;

                p = p - old_pairs_i + new_pairs_i;
                if (new_cnt_i > 0)
                    mp[nums[i]].second = new_pairs_i;
                else
                    mp.erase(nums[i]);

                i++;
            }

            j++;
        }

        return ans;
    }
};
