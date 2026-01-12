class Solution {
public:
    int cameras=0;
    // 0:has camera, 1:covered, 2:needs camera
    int fun(TreeNode* root){
        if(root==NULL){
            return 1;
        }

        int lh = fun(root->left);
        int rh = fun(root->right);

        if(lh==2 || rh==2){
            cameras++;
            return {0};
        }

        if(lh==0 || rh==0){
            return {1};
        }

        return {2};
    }

    int minCameraCover(TreeNode* root) {
        int rh = fun(root);

        if(rh==2) cameras++;

        return cameras;
    }
};