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

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        map<int,map<int,multiset<int>>>nodes;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int v = temp.second.first;
            int l = temp.second.second;
            nodes[v][l].insert(node->val);

            if(node->left) q.push({node->left,{v-1,l+1}});
            if(node->right) q.push({node->right,{v+1,l+1}});
        }

        for(auto a:nodes){
            vector<int>temp;
            for(auto b:a.second){
                temp.insert(temp.end(),b.second.begin(),b.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};