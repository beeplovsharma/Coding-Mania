class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
    vector<int> ans;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        // Remove elements out of this window from the front
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        // Remove elements smaller than the current element from the back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        // Add current element at the back of the deque
        dq.push_back(i);
        
        // If window is fully within the array, add to result
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }
    
    return ans;
    }
};