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
    void hasPathSum(TreeNode* root, int targetSum,vector<int>&ds,vector<vector<int>>&ans){
        if(root==NULL) return;

        ds.push_back(root->val);

        if(root->left==NULL && root->right==NULL && targetSum == root->val){
            ans.push_back(ds);
        }

        int newTargetSum = targetSum - root->val;
        hasPathSum(root->left,newTargetSum,ds,ans);
        hasPathSum(root->right,newTargetSum,ds,ans);
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ds;
        vector<vector<int>>ans;
        hasPathSum(root,targetSum,ds,ans);
        return ans;
    }
};