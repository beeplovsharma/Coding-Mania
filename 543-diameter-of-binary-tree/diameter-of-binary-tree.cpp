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
    struct DiaPair{
        int height;
        int diameter;
    };

    DiaPair fun(TreeNode* root){
        if(root==NULL){
            DiaPair base;
            base.height = -1; // height of null is -1
            base.diameter = 0;
            return base;
        }

        DiaPair left = fun(root->left);   // faith
        DiaPair right = fun(root->right); // faith

        DiaPair self;
        self.height = max(left.height, right.height) + 1;

        int pathThroughRoot = left.height + right.height + 2;
        self.diameter = max({left.diameter, right.diameter, pathThroughRoot}); // expectation

        return self;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return fun(root).diameter;
    }
};