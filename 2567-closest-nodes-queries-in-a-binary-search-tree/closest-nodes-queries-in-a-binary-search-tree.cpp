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
    void inorderT(TreeNode* root, vector<int>& inorder){
        if(root==NULL) return;

        inorderT(root->left,inorder);
        inorder.push_back(root->val);
        inorderT(root->right,inorder);
    }

    int minHandle(vector<int>&arr,int x){
        int low=0,high=arr.size()-1;
        int lower = -1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(arr[mid]<=x){
                lower = arr[mid];
                low = mid+1;
            }
            else high = mid-1;
        }
        return lower;
    }

    int maxHandle(vector<int>&arr,int x){
        int low=0,high=arr.size()-1;
        int higher = -1;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(arr[mid]>=x){
                higher = arr[mid];
                high = mid-1;
            }
            else low = mid+1;
        }
        return higher;
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>inorder;
        inorderT(root,inorder);
        vector<vector<int>>ans;
        int n = inorder.size();

        for(auto x:queries){

            int mini = minHandle(inorder,x);
            int maxi = maxHandle(inorder,x);

            ans.push_back({mini,maxi});
        }
        return ans;
    }
};