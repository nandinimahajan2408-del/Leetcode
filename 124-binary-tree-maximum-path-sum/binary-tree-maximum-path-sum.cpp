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
    int maxpath(TreeNode*root,int &maxi){
        if(root==nullptr) return 0;
    
           int lh= max(maxpath(root->left,maxi),0);
           int rh=max(maxpath(root->right,maxi),0);
        maxi=max(maxi,lh+rh+root->val);

        return max(lh,rh)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
       int maxi=INT_MIN;
       maxpath(root,maxi);
       return maxi;
    }
};