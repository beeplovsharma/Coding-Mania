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
    void fun(TreeNode* root,int &cnt,int &maxx){
        if(root == NULL) return;

        if(root->val >= maxx){
            cnt++;
        }

        fun(root->left,cnt,(root->val >= maxx) ? root->val : maxx);
        fun(root->right,cnt,(root->val >= maxx) ? root->val : maxx);
    }
    int goodNodes(TreeNode* root) {
        int maxx = root->val;
        int cnt = 0;
        fun(root,cnt,maxx);
        return cnt;
    }
};