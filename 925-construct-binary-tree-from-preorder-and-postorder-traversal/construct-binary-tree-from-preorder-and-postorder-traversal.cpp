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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,int prestart,int poststart,int preend){

        if(prestart>preend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart==preend) return root;
        int nextNode = preorder[prestart+1];
        int j = poststart;

        while(postorder[j]!=nextNode) j++;

        int num = j-poststart+1;
        root->left = solve(preorder,postorder,prestart+1,poststart,prestart+num);
        root->right = solve(preorder,postorder,prestart+num+1,j+1,preend);


        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int ind = 0;
        TreeNode* root = solve(preorder,postorder,0,0,n-1);
        return root;
    }
};