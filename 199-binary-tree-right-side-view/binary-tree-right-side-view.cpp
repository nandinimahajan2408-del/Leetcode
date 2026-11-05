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
    void recursion(TreeNode*root,vector<int>&ans,int level){
        if(root==nullptr){
            return ;
        }
        if(ans.size()==level) ans.push_back(root->val);
        recursion(root->right,ans,level+1);
        recursion(root->left,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
      // level order travesal.so last node at each level will be part of rightside view node
      //we can try root,right,left by recursion and if res size is =level then we can add to ans
      vector<int>ans;
      recursion(root,ans,0);
      return ans;
    }
};