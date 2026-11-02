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
 //solve by level order traversal

class Solution {
    void levelorder(TreeNode*root,vector<vector<int>>&ans){

        queue<TreeNode*>q;
        q.push(root);
        int rev=1;

        while(!q.empty()){
            vector<int>level;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode*node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            rev=!rev;
            if(rev==0) ans.push_back(level);
            else {
                reverse(level.begin(),level.end());
                ans.push_back(level);
            }
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       if(root==nullptr) return ans;
       levelorder(root,ans);
       return ans; 
    }
};