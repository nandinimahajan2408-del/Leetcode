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
    bool checkvalid(TreeNode*root,long long l,long long r){
        if(root==nullptr) return true;
        if(root->val>l&&root->val<r) {
            return checkvalid(root->left,l,root->val)&&checkvalid(root->right,root->val,r);
        }
        return false;    
    }
public:
    bool isValidBST(TreeNode* root) {
       return checkvalid(root,LLONG_MIN,LLONG_MAX);
    }
};