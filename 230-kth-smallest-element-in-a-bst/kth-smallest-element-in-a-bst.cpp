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
    vector<int>findinorder(TreeNode*root,vector<int>&inorder){
        if(root==nullptr) return inorder;

        findinorder(root->left,inorder);
        inorder.push_back(root->val);
        findinorder(root->right,inorder);
        return inorder;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
       vector<int>inorder;
       findinorder(root,inorder);
       return inorder[k-1]; 
    }
};