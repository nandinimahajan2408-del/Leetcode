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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       queue<TreeNode*>q;

       if(root==nullptr) return ans;
       q.push(root);

       while(!q.empty()){
        int sizee=q.size();
        vector<int>level;

        for(int i=0;i<sizee;i++){
            TreeNode* v=q.front();
             q.pop();
             level.push_back(v->val);
            if(v->left) q.push(v->left);
            if(v->right) q.push(v->right);
        }
        ans.push_back(level);
       }
       return ans; 
    }
};