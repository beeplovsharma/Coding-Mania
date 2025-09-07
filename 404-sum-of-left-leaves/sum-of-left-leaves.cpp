class Solution {
public:
    int fun(TreeNode* root,int track){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL && track == 1) return root->val;

        int lt = fun(root->left,1);
        int rt = fun(root->right,2);

        return (lt+rt);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return fun(root,0);
    }
};