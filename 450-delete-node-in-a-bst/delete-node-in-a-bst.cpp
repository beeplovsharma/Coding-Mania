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
    int calcMax(TreeNode* root){
        if(root->right!=NULL) return calcMax(root->right);
        else{
            return root->val;
        }
    }
    TreeNode* fun(TreeNode* root, int key){
        if(root==NULL) return NULL;

        if(key < root->val){
            root->left = fun(root->left,key);
        }else if(key > root->val){
            root->right = fun(root->right,key);
        }else{
            if(root->left!=NULL && root->right!=NULL){
                int lmax = calcMax(root->left);
                root->val = lmax;
                root->left = fun(root->left,lmax);
                return root;
            }else if(root->left!=NULL){
                return root->left;
            }else if(root->right!=NULL){
                return root->right;
            }else{
                return NULL;
            }
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return fun(root,key);
    }
};