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
    TreeNode* markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track,int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* sNode;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                if(node->val == start) sNode = node;
                q.pop();
                if(node->left) {
                    parent_track[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent_track[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        return sNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        TreeNode* sNode = markParents(root,parent_track,start);

        queue<TreeNode*>q;
        q.push(sNode);
        unordered_map<TreeNode*,bool>visited;
        visited[sNode] = true;
        int cur_level = 0;
        
        while(!q.empty()){
            cur_level++;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front(); q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }
        return cur_level-1;
    }
};