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
    int tilt;
    int fun(TreeNode* root){
        if(root==NULL) return 0;

        int lsum = fun(root->left);
        int rsum = fun(root->right);

        tilt += abs(lsum-rsum);

        return lsum+root->val+rsum;
    }
    int findTilt(TreeNode* root) {
        tilt=0;
        fun(root);
        return tilt;
    }
};