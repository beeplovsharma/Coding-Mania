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
    bool isLeaf(TreeNode *root){
        return (!root->left && !root->right);
    }
    int minDepth(TreeNode* root) {
            if(root==NULL) return 0;
            queue<pair<TreeNode*,int>>q;
            q.push({root,1});
            while(!q.empty()){
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                int level = p.second;

                if(isLeaf(node)) return level;
                if(node->left) q.push({node->left,level+1});
                if(node->right) q.push({node->right,level+1});
            }
            return 0;
    }
};