class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL) return NULL;
        if(original == target) return cloned;

        TreeNode* lt = getTargetCopy(original->left, cloned->left, target);
        if(lt != NULL) return lt;

        return getTargetCopy(original->right, cloned->right, target);
    }
};
