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
    bool helper(TreeNode*rightroot,TreeNode*leftroot){
        if(leftroot==nullptr&&rightroot==nullptr) return true;
        if(leftroot==nullptr||rightroot==nullptr) return false;
        if(leftroot->val!=rightroot->val) return false;

         return helper(rightroot->right,leftroot->left)&&helper(rightroot->left,leftroot->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};