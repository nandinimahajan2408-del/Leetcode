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
    void helper(TreeNode*root,int k,int &num,int &cnt){
        if(root==nullptr) return;
        helper(root->left,k,num,cnt);
        cnt++;
        if(cnt==k) {
            num=root->val;
            return;
        }
        if(cnt<k) helper(root->right,k,num,cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int num;
        int cnt=0;
      helper(root,k,num,cnt);
      return num;
    }
};