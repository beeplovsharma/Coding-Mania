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
    class BSTPair{
        public:
            int height;
            bool isBBT;
    };
public:
    BSTPair fun(TreeNode* root){
        if(root==NULL){
            BSTPair bp;
            bp.height=0;
            bp.isBBT=true;
            return bp;
        }

        BSTPair lt = fun(root->left);
        BSTPair rt = fun(root->right);

        BSTPair cur;
        cur.isBBT = lt.isBBT && rt.isBBT && (abs(lt.height-rt.height)<=1);
        cur.height = 1+max(lt.height,rt.height);

        return cur;
    }
    bool isBalanced(TreeNode* root) {
        BSTPair ans = fun(root);
        return ans.isBBT;
    }
};