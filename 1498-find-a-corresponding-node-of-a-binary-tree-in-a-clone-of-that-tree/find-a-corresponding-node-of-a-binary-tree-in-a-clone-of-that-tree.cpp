class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL) return NULL;

        if(original==target) return cloned;
        
        TreeNode* lt = getTargetCopy(original->left,cloned->left,target);
        if(lt!=NULL) return lt;

        TreeNode* rt = getTargetCopy(original->right,cloned->right,target);
        if(rt!=NULL) return rt;

        return NULL;
    }
};
