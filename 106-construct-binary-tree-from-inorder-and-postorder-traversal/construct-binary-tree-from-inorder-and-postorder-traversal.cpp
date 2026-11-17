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
    TreeNode*build(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,map<int,int>&mpp){
        if(poststart>postend||instart>inend) return nullptr;

        TreeNode*root=new TreeNode(postorder[postend]);
        int inroot=mpp[root->val];
        int numsleft=inroot-instart;

        root->left=build(inorder,instart,instart+numsleft,postorder,poststart,poststart+numsleft-1,mpp);
        root->right=build(inorder,inroot+1,inend,postorder,poststart+numsleft,postend-1,mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       map<int,int>mpp;
       for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]]=i;
       }
       int n=postorder.size();
       TreeNode*root=build(inorder,0,n-1,postorder,0,n-1,mpp);
       return root; 
    }
};