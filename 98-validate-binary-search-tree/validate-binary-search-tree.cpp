class Solution {
public:
    typedef long long ll;

    class BSTPair{
        public:
            bool isBST;
            ll min;
            ll max;
    };

    BSTPair fun(TreeNode* root){
        if(root==NULL){
            BSTPair bp;
            bp.min = LLONG_MAX;
            bp.max = LLONG_MIN;
            bp.isBST = true;
            return bp;
        }

        BSTPair lt = fun(root->left);
        BSTPair rt = fun(root->right);

        BSTPair cur;
        cur.isBST = lt.isBST && rt.isBST && (lt.max < root->val && root->val < rt.min);
        cur.min = min({lt.min,(ll)root->val,rt.min});
        cur.max = max({lt.max,(ll)root->val,rt.max});

        return cur;
    }

    bool isValidBST(TreeNode* root) {
        BSTPair ans = fun(root);
        return ans.isBST;
    }
};