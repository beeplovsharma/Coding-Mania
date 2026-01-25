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
    int cameras;

    // 0:has camera | 1:needs camera | 2:covered
    int fun(TreeNode* root){
        if(root==NULL) return 2;

        int lh = fun(root->left);
        int rh = fun(root->right);

        if(lh==1 || rh==1){
            cameras++;
            return 0;
        }

        if(lh==0 || rh==0){
            return 2;
        }

        return 1;
    }
    int minCameraCover(TreeNode* root) {
        cameras=0;
        int res = fun(root);
        if(res==1) cameras++;
        return cameras;   
    }
};