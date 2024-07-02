/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, string &s, vector<string> &v)
    {
        if(root==NULL) return;
        if (!root->left && !root->right)
        {
            s += to_string(root->val);
            v.push_back(s);
            s.pop_back();
            return;
        };
        s += to_string(root->val);
        solve(root->left,s, v);
        solve(root->right,s, v);
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string s;
        vector<string>v;
        solve(root,s,v);
        int ans = 0;
        for (auto x : v)
            ans+= stoi(x);
        return ans;
    }
};