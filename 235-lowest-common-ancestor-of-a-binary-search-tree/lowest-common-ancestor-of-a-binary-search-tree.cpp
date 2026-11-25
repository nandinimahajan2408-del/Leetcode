/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode*findlca(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==nullptr)return root;
        if(p->val<root->val&&q->val<root->val){
            return findlca(root->left,p,q);
        }
        if(p->val>root->val&&q->val>root->val){
            return findlca(root->right,p,q);
        }
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==nullptr) return nullptr;
       TreeNode*ans=findlca(root,p,q);
       return ans;
    }
};
