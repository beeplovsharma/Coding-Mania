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
    int solve(TreeNode* root,int &maxPathSum){
        if(root==NULL) return 0;

        int lh = solve(root->left,maxPathSum);
        if(lh<0) lh = 0;
        int rh = solve(root->right,maxPathSum);
        if(rh<0) rh = 0;

        maxPathSum = max(maxPathSum,lh+root->val+rh);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        solve(root,maxPathSum);
        return maxPathSum;
    }
};