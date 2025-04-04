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
    pair<TreeNode*, int> fun(TreeNode* root){
        if(root==NULL) return {NULL,0};

        auto left = fun(root->left);
        auto right = fun(root->right);

        if(left.second > right.second) return {left.first,left.second+1};
        if(left.second < right.second) return {right.first,right.second+1};

        return {root,left.second+1};

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return fun(root).first;
    }
};