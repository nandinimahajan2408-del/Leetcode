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
    TreeNode*build(vector<int>&inorder,int instart,int inend,vector<int>&preorder,int prestart,int preend,map<int,int>&mpp){
        if(prestart>preend||instart>inend) return nullptr;

        TreeNode*root=new TreeNode(preorder[prestart]);
        int inroot=mpp[root->val];
        int numsleft=inroot-instart;

        root->left=build(inorder,instart,inroot-1,preorder,prestart+1,prestart+numsleft,mpp);
        root->right=build(inorder,inroot+1,inend,preorder,prestart+numsleft+1,preend,mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      map<int,int>mpp;
      int n=preorder.size();
      for(int i=0;i<n;i++){
        mpp[inorder[i]]=i;
      }
      TreeNode*root=build(inorder,0,n-1,preorder,0,n-1,mpp);
      return root;  
    }
};