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
    void solve(TreeNode* root, vector<string>&ans,string s){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            s+=to_string(root->val);
            ans.push_back(s);
        }

        s+=to_string(root->val);
        s+="->";
        solve(root->left,ans,s);
        solve(root->right,ans,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s;
        solve(root,ans,s);
        return ans;
    }
};