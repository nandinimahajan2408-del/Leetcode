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
    void findinorder(TreeNode*root,vector<int>&ans){
        if(root==nullptr){
            ans.push_back(INT_MIN);
             return;
        }
         ans.push_back(root->val);
        findinorder(root->left,ans);
       
        findinorder(root->right,ans);
        return ;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>ans1,ans2;
      findinorder(p,ans1);
      findinorder(q,ans2);
      if(ans1.size()!=ans2.size()) return false;
      for(int i=0;i<ans1.size();i++){
        if(ans1[i]!=ans2[i]) return false;
      }
      return true; 
    }
};