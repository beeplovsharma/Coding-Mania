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
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }

    bool isBST(TreeNode* root,long mini,long maxi){
        if(root==NULL) return true;

        if(mini >= root->val || root->val >= maxi) return false;

        return isBST(root->left,mini,root->val) && isBST(root->right,root->val,maxi);
    }
};