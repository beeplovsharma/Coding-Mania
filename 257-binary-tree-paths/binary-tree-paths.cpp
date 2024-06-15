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
    string toStringC(vector<int>arr){
        string ans="";
        for(int i=0;i<arr.size();i++){
            ans+=to_string(arr[i]);
            if(i==arr.size()-1) continue;
            ans+="->";
        }
        return ans;
    }
    void solve(TreeNode* root,vector<int> arr,vector<string>&ans){
        if(root==NULL) return;
        arr.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(toStringC(arr));
            return;
        }
        solve(root->left,arr,ans);
        solve(root->right,arr,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL) return ans;
        vector<int>arr;
        solve(root,arr,ans);
        return ans;
    }
};