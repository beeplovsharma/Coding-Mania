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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);

        if(root->val < val){
            if(root->right) insertIntoBST(root->right,val);
            else{
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
            }
        }

        else{
            if(root->left) insertIntoBST(root->left,val);
            else{
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
            }
        }
        return root;
    }
};