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
    int finddia(TreeNode*node,int&dia){
        if(node==nullptr) return 0;
         int leftdia=finddia(node->left,dia);
      int rightdia=finddia(node->right,dia);

      dia=max(dia,leftdia+rightdia);
      return 1+max(leftdia,rightdia);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if(root==nullptr) return 0;
      int dia=0;
     finddia(root,dia);
     return dia;
       }
};