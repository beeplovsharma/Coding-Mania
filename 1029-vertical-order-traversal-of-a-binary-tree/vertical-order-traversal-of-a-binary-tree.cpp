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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;

        queue<pair<TreeNode*,pair<int,int>>>q; // <Node,<Vertical,Level>>
        q.push({root,{0,0}});

        map<int,map<int,multiset<int>>>mp; // <Vertical,<Level,Node->Val>>
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int v = temp.second.first;
            int l = temp.second.second;
            mp[v][l].insert(node->val);

            if(node->left) q.push({node->left,{v-1,l+1}});
            if(node->right) q.push({node->right,{v+1,l+1}});
        }

        for(auto p:mp){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};